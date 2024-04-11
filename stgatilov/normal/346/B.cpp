//#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 128;

char astr[SIZE], bstr[SIZE], img[SIZE];
int n, m, k;
int pref[SIZE];

int res[SIZE][SIZE][SIZE];
int father[SIZE][SIZE][SIZE];

void relax(int &xres, int &xf, int nres, int nf) {
	if (xres < nres) {
		xres = nres;
		xf = nf;
	}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%s%s%s", astr, bstr, img);
	n = strlen(astr);
	m = strlen(bstr);
	k = strlen(img);

	pref[0] = 0;
	{
	int i = 1, j = 0;
	while (i < k) {
		if (img[i] == img[j]) {
			i++;  j++;
			pref[i] = j;
		}
		else {
			if (j == 0) {
				i++;
				pref[i] = 0;
			}
			else j = pref[j];
		}
	}
	}
//	for (int i = 0; i<=k; i++) printf("%d ", pref[i]); printf("\n");

	memset(res, -63, sizeof(res));
	memset(father, -63, sizeof(father));
	res[0][0][0] = 0;
	for (int i = 0; i<=n; i++)
		for (int j = 0; j<=m; j++)
			for (int u = 0; u<k; u++) {
				int tres = res[i][j][u];
				if (tres < 0) continue;

				if (i < n) relax(res[i+1][j][u], father[i+1][j][u], tres, -1);
				if (j < m) relax(res[i][j+1][u], father[i][j+1][u], tres, -2);
				if (astr[i] == bstr[j]) {
					char c = astr[i];

					int v = u;
					while (v > 0 && c != img[v]) v = pref[v];
					if (c == img[v]) v++;

					if (v == k) continue;
                    relax(res[i+1][j+1][v], father[i+1][j+1][v], tres+1, u);
				}
			}

	int ans = -1;
	int best = -1;
	for (int u = 0; u<k; u++)
		relax(ans, best, res[n][m][u], u);

	string word;
	int i = n, j = m, u = best;
	while (i+j > 0) {
		int ff = father[i][j][u];
		if (ff == -1) i--;
		else if (ff == -2) j--;
		else {
			i--;  j--;  u = ff;
			assert(astr[i] == bstr[j]);
			word += astr[i];
		}
	}

	reverse(word.begin(), word.end());

	printf("%s\n", word.empty() ? "0" : word.c_str());

	return 0;
}