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

const int SIZE = 200;
const int RULES = 12;

int k, n;
char str[SIZE];
int imlen[RULES];
char image[RULES][SIZE];
int minc[RULES], maxc[RULES];

int lcp[SIZE][SIZE];

int cnts[SIZE][SIZE][RULES];

set<string> ans;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%s", str);
	k = strlen(str);
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%s%d%d", image[i], &minc[i], &maxc[i]);
		imlen[i] = strlen(image[i]);
	}

	for (int i = k; i>=0; i--)
		for (int j = k; j>=0; j--) {
			if (i == k || j == k)
				lcp[i][j] = 0;
			else
				lcp[i][j] = (str[i] == str[j] ? lcp[i-1][j-1] + 1 : 0);
		}

	for (int i = 0; i<k; i++)
		for (int r = 0; r<n; r++)
			for (int u = 0; u<=imlen[r]; u++) {
				bool ok = true;
				for (int j = i+1; j<=k; j++) {
					if (image[r][u+j-1-i] != str[j-1])
						ok = false;
					if (ok)
						cnts[i][j][r]++;
				}
			}


	for (int i = 0; i<k; i++)
		for (int j = i+1; j<=k; j++) {
			bool ok = true;
			for (int r = 0; r<n; r++) {
				int q = cnts[i][j][r];
				ok &= q >= minc[r] && q <= maxc[r];
			}
			if (ok)
				ans.insert(string(str+i, str+j));
		}

	printf("%d\n", ans.size());
//	for (auto it = ans.begin(); it != ans.end(); it++) printf("%s\n", it->c_str());

	return 0;
}