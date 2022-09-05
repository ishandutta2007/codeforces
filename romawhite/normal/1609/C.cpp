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
const int MAX = 1000007;
const int MOD = 1000000007;

int p[MAX];

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	for(int i = 2; i * i < MAX; ++i)
		if (!p[i])
			for(int j = i * i; j < MAX; j += i)
				p[j] = 1;

	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n, e;
		cin >> n >> e;
		VI A(n);
		FOR(i,0,n) {
			cin >> A[i];
		}
		Int res = 0;
		FOR(i,0,e) {
			int last0 = 0;
			int last1 = -1;
			for(int j = i; j < n; j += e) {
				if (A[j] > 1) {
					if (!p[A[j]]) {
						if (last0 >= 0)
							res += last0;
						last1 = last0;
					} else {
						last1 = -1;
					}
					last0 = 0;
				} else {
					res += last1 + 1;
					last0 ++;
				}
			}
		}
		cout << res << endl;

	}
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}