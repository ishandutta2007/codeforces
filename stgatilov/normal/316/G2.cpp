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

const int SIZE = 2<<10;
const int RULES = 12;

int k, n;
char str[SIZE];
int imlen[RULES];
char image[RULES][SIZE];
int minc[RULES], maxc[RULES];

int lcp[SIZE][SIZE];
void CalcLCP(char *a, char *b) {
	int ak = strlen(a);
	int bk = strlen(b);
	for (int i = ak; i>=0; i--)
		for (int j = bk; j>=0; j--) {
			if (i == ak || j == bk)
				lcp[i][j] = 0;
			else
				lcp[i][j] = (a[i] == b[j] ? lcp[i+1][j+1] + 1 : 0);
		}
}

int rpl[SIZE];
bool goodss[SIZE][SIZE];

struct Word {
	int a, b;
};
inline int cmp(Word x, Word y) {
	int xl = x.b - x.a;
	int yl = y.b - y.a;
	if (xl != yl)
		return (xl < yl ? -1 : 1);
	int comm = lcp[x.a][y.a];
	if (comm < xl)
		return (str[x.a+comm] < str[y.a+comm] ? -1 : 1);
	return 0;
}

inline bool operator< (Word x, Word y) {
	return cmp(x, y) < 0;
}
inline bool operator== (Word x, Word y) {
	return cmp(x, y) == 0;
}

//set<Word> ans;

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

	memset(goodss, true, sizeof(goodss));

	for (int r = 0; r<n; r++) {
		CalcLCP(str, image[r]);
		for (int i = 0; i<k; i++) {
			memset(rpl, 0, sizeof(rpl));
			for (int u = 0; u<=imlen[r]; u++) {
				int comm = lcp[i][u];
//				printf("%d %d %d -> %d\n", r, i, u, comm);
				rpl[comm]++;
			}
			for (int q = k; q>=0; q--) rpl[q] += rpl[q+1];

			for (int j = i+1; j<=k; j++) {
				int tt = rpl[j-i];
/*				printf("[%d; %d) ", i, j);
				for (int w = i; w<j; w++) printf("%c", str[w]);
				printf(" occurs in %s : %d\n", image[r], tt);*/
				if (tt < minc[r] || tt > maxc[r])
					goodss[i][j] = false;
			}
		}
	}

	CalcLCP(str, str);
	vector<Word> ans;
	for (int i = 0; i<k; i++)
		for (int j = i+1; j<=k; j++) {
			if (goodss[i][j]) {
				Word w;
				w.a = i;
				w.b = j;
				ans.push_back(w);
			}
		}

	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

	printf("%d\n", ans.size());
//	for (auto it = ans.begin(); it != ans.end(); it++) printf("%s\n", it->c_str());

	return 0;
}