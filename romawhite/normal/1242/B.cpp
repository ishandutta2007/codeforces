#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
 
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
 
typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
 
int IT_MAX = 1 << 17;
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first
 
set <pii> Sx;
vector <int> conn[200050];
 
bool pchk[200050];
 
int lc = 1;
vector <int> Vl[200050];
 
int r[200050];
int sz[200050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		Sx.emplace(t1, t2);
		Sx.emplace(t2, t1);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
 
	int p = 1;
	for (i = 2; i <= N; i++) if (conn[i].size() < conn[p].size()) p = i;
	for (auto it : conn[p]) pchk[it] = true;
	for (i = 1; i <= N; i++) if (!pchk[i]) Vl[1].push_back(i);
	for (i = 1; i <= N; i++) {
		if (!pchk[i]) continue;
		lc++;
		Vl[lc].push_back(i);
	}
 
	for (i = 1; i <= lc; i++) r[i] = i;
	for (i = 1; i <= lc; i++) {
		for (j = i + 1; j <= lc; j++) {
			bool chk = false;
			for (auto it1 : Vl[i]) {
				for (auto it2 : Vl[j]) {
					if (Sx.count(pii(it1, it2))) continue;
					chk = true;
					break;
				}
			}
			if (chk) r[root(i)] = root(j);
		}
	}
 
	int cnt = 0;
	for (i = 1; i <= lc; i++) sz[root(i)] += Vl[i].size();
 
	vector <int> Va;
	for (i = 1; i <= lc; i++) if (r[i] == i) Va.push_back(sz[i]);
	sort(all(Va));
 
	printf("%d\n", (int)Va.size() - 1);
}
//*/