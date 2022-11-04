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

const int SIZE = 100<<10;
const int SQRT = 400;
int n, m, q;
vector<int64> arr(SIZE);
vector<vector<int>> groups(SIZE);

int b;
vector<bool> isBig;
vector<int> bigList;
vector<int> bigIdx(SIZE, -1);
vector<vector<int>> inBigs(SIZE);
int matr[SQRT][SQRT];
int fmatr[SIZE][SQRT];
vector<int64> bigAdd(SQRT);
vector<int64> resBig(SQRT);

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i<n; i++) scanf("%I64d", &arr[i]);
	for (int i = 0; i<m; i++) {
		int sz;
		scanf("%d", &sz);
		for (int j = 0; j<sz; j++) {
			int t;
			scanf("%d", &t);
			t--;
			groups[i].push_back(t);
		}
	}

	int ss = int(sqrt(double(SIZE))) + 1;
    isBig.resize(m, false);
	for (int i = 0; i<m; i++) {
		isBig[i] = (groups[i].size() >= ss);
		if (isBig[i]) {
			bigIdx[i] = bigList.size();
			bigList.push_back(i);
		}
	}
	b = bigList.size();

	for (int i = 0; i<b; i++) {
		int gi = bigList[i];
		for (int j = 0; j<groups[gi].size(); j++) {
			int q = groups[gi][j];
			inBigs[q].push_back(i);
			resBig[i] += arr[q];
		}
	}

	vector<int> tmp(n, 0);
	for (int i = 0; i<b; i++) {
		int gi = bigList[i];
		for (int j = 0; j<groups[gi].size(); j++) {
			int q = groups[gi][j];
			tmp[q]++;
		}
		for (int j = i+1; j<b; j++) {
			int bj = bigList[j];
			int intSz = 0;
			for (int u = 0; u<groups[bj].size(); u++) {
				int qq = groups[bj][u];
				intSz += tmp[qq];
			}
            matr[i][j] = matr[j][i] = intSz;
		}
		for (int j = 0; j<groups[gi].size(); j++) {
			int q = groups[gi][j];
			tmp[q]--;
		}
		matr[i][i] = groups[gi].size();
	}

	for (int i = 0; i<m; i++) {
		if (isBig[i]) {
			for (int j = 0; j<b; j++) fmatr[i][j] = matr[bigIdx[i]][j];
		}
		else {
			for (int j = 0; j<groups[i].size(); j++) {
				int t = groups[i][j];
				for (int u = 0; u<inBigs[t].size(); u++) {
					int e = inBigs[t][u];
					fmatr[i][e]++;
				}
			}
		}
	}

	for (int uhj = 0; uhj<q; uhj++) {
		char tt;
		scanf(" %c", &tt);
		if (tt == '?') {
			int g;
			scanf("%d", &g);
			g--;

			int64 ans = 0;
			if (isBig[g]) {
				ans = resBig[bigIdx[g]];
			}
			else {
				for (int i = 0; i<groups[g].size(); i++)
					ans += arr[groups[g][i]];
				for (int i = 0; i<b; i++)
					ans += fmatr[g][i] * bigAdd[i];
			}
			printf("%I64d\n", ans);
		}
		else {
			int g;
			int64 add;
			scanf("%d%I64d", &g, &add);
			g--;

			if (isBig[g]) {
				int gg = bigIdx[g];
				bigAdd[gg] += add;
				for (int i = 0; i<b; i++)
					resBig[i] += matr[i][gg] * add;
			}
			else {
				for (int i = 0; i<groups[g].size(); i++) {
					int t = groups[g][i];
					arr[t] += add;
				}
				for (int i = 0; i<b; i++)
					resBig[i] += fmatr[g][i] * add;
			}
		}
	}


	return 0;
}