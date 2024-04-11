#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>  
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
#include <random>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 100007;
const int MOD = 998244353;

VI G[MAX];
bool U[MAX];

void dfs(int v) {
	U[v] = true;
	for(int to: G[v]) {
		if (!U[to])
			dfs(to);
	}
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng;
	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n;
		cin >> n;
		FOR(i,0,n) {
			G[i].clear();
			U[i] = false;
		}
		int v;
		FOR(i,0,2) {
			vector<PII> A;
			FOR(j,0,n) {
				int x;
				cin >> x;
				A.push_back(MP(x, j));
			}
			sort(ALL(A));
			reverse(ALL(A));
			v = A[0].second;
			FOR(j,0,n - 1) {
				G[A[j + 1].second].push_back(A[j].second);
			}	
		}
		dfs(v);
		FOR(i,0,n) {
			if (U[i])
				cout << 1;
			else
				cout << 0;
		}
		cout << endl;
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}