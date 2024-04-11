#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1010;

int N;

int par[MAXN];
int find(int n) {
	if (par[n] == n) return n;
	return par[n] = find(par[n]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	par[a] = b;
	return true;
}

vector<int> vA;
vector<int> vB;

int main() {
	scanf("%d", &N);

	for(int i = 1; i <= N; ++i) {
		par[i] = i;
	}

	int numans = 0;
	for(int i = 1; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (!merge(a, b)) {
			vA.push_back(a);
			vB.push_back(b);
			++numans;
		}
	}

	printf("%d\n", numans);

	int j = 0;
	for(int i = 2; i <= N; ++i) {
		if (find(i) != find(1)) {
			int a = vA[j];
			int b = vB[j];
			++j;
			printf("%d %d 1 %d\n", a, b, i);
			merge(1, i);
		}
	}

	return 0;
}