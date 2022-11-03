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
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 5<<20;
const int NUM = 1<<20;
const int LOGN = 20;

int n, r, c;
vector<string> words;
int lensum[2*NUM];
int nxt[NUM];
int nxx[LOGN+1][NUM];
int nxr[NUM], nxc[NUM];

char buff[SIZE];
int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &r, &c);
	for (int i = 0; i<n; i++) {
		scanf("%s", buff);
		words.push_back(buff);
	}

	lensum[0] = 0;
	for (int i = 0; i<=2*n; i++)
		lensum[i+1] = lensum[i] + words[i%n].size() + 1;

	for (int i = 0; i<n; i++) {
		int wright = lensum[i] + c + 1;
		int idx = lower_bound(lensum, lensum+2*n, wright) - lensum;
		if (lensum[idx] != wright) idx--;
		nxt[i] = min(idx, n);
	}
	nxt[n] = n;

	for (int i = 0; i<=n; i++) nxx[0][i] = nxt[i];
	for (int i = 1; i<=LOGN; i++) {
		for (int j = 0; j<=n; j++)
			nxx[i][j] = nxx[i-1][nxx[i-1][j]];
	}

	for (int i = 0; i<=n; i++) nxr[i] = i;
	for (int i = 0; i<=LOGN; i++) {
		if (!(r & (1<<i))) continue;

		memcpy(nxc, nxr, sizeof(nxc));
		for (int j = 0; j<=n; j++)
			nxr[j] = nxx[i][nxc[j]];
	}

	int ans = -1;
	int bestl = -1, bestr = -1;
	for (int i = 0; i<=n; i++)
		if (nxr[i] - i > ans) {
			ans = nxr[i] - i;
			bestl = i;
			bestr = nxr[i];
		}


	int curr = bestl;
	while (curr != bestr) {
		int nn = nxt[curr];
		if (nn > bestr) nn = bestr;
		for (int i = curr; i<nn; i++) {
			if (i > curr) printf(" ");
			printf("%s", words[i].c_str());
		}
		printf("\n");
		curr = nn;
	}

	return 0;
}