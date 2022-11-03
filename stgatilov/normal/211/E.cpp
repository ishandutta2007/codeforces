#pragma comment(linker, "/STACK:30000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <bitset>
#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;
typedef long long int64;
#define E(c) fprintf(stderr, #c)
#define Eo(c) std::cerr << #c << " = " << (c) << std::endl

const int SIZE = 5<<10;

struct Res {
	inline Res() { sum = -1000000000; }

	int sum;
	bitset<SIZE> mask;
};

int n;
vector<int> nbr[SIZE];
int deg[SIZE];
Res res[SIZE][2][2][3];
vector<Res> inter[SIZE][2][2][3];
vector<int> sons[SIZE];

inline bool Comp(int a, int b) {
	return !(a>0 && b>0 && a != b);
}

int bvect[SIZE];
int bvs;
void Add(Res &res, const Res &a, const Res &b) {
	if (a.sum < 0 || b.sum < 0) {
		res = Res();
		return;
	}

	res.sum = a.sum + b.sum;
	res.mask.reset();

	bvs = 0;
	for (int i = 0; i<=n; i++) if (b.mask[i])
		bvect[bvs++] = i;

	for (int i = 0; i<=n; i++) if (a.mask[i])
		for (int j = 0; j<bvs; j++)
			res.mask[i + bvect[j]] = true;
}

void Relax(Res &a, const Res &b) {
	if (a.sum > b.sum) return;
	if (a.sum < b.sum) {
		a = b;
		return;
	}
	a.mask |= b.mask;
}

bool used[SIZE];
void DFS(int u) {
	used[u] = true;

	for (int i = 0; i<nbr[u].size(); i++) {
		int v = nbr[u][i];
		if (used[v]) continue;

		DFS(v);
		sons[u].push_back(v);
	}
	deg[u] = sons[u].size();

	for (int l = 0; l<3; l++) {
		for (int a = 0; a<2; a++)
			for (int b = 0; b<2; b++)
				inter[u][a][b][l].resize(deg[u] + 1, Res());

		Res &tr = inter[u][l==1][l==2][l][0];
		tr.sum = (l != 0);
		tr.mask[(l==1)] = true;
	}

	Res tmp;
	for (int k = 0; k<deg[u]; k++) {
		for (int l = 0; l<3; l++)
			for (int a = 0; a<2; a++)
				for (int b = 0; b<2; b++) {
					const Res &tres = inter[u][a][b][l][k];
					if (tres.sum < 0) continue;

					int tson = sons[u][k];
					for (int tl = 0; tl<3; tl++) if (Comp(tl, l))
						for (int ta = 0; ta<2; ta++)
							for (int tb = 0; tb<2; tb++) {
								const Res &addres = res[tson][ta][tb][tl];
								if (addres.sum < 0) continue;
								Add(tmp, tres, addres);
								Relax(inter[u][a|ta][b|tb][l][k+1], tmp);
							}
				}
	}

	for (int l = 0; l<3; l++)
		for (int a = 0; a<2; a++)
			for (int b = 0; b<2; b++) {
				res[u][a][b][l] = inter[u][a][b][l][deg[u]];
//				printf("%d %d %d %d: %d\n", u, a, b, l, res[u][a][b][l]);
			}
}

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i<n-1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;  y--;
		nbr[x].push_back(y);
		nbr[y].push_back(x);
	}

	memset(res, -63, sizeof(res));
	DFS(0);

	Res ans;
	for (int l = 0; l<3; l++) Relax(ans, res[0][1][1][l]);
//	printf("%d\n", ans.sum);

	vector<int> pr;
	for (int i = 0; i<=n; i++) if (ans.mask[i]) pr.push_back(i);
	printf("%d\n", pr.size());
	for (int i = 0; i<pr.size(); i++) printf("%d %d\n", pr[i], ans.sum - pr[i]);

	return 0;
}