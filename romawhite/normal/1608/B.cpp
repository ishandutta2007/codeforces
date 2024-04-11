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
const int MAX = 1000007;
const int MOD = 998244353;

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng;
	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n, a, b;
		cin >> n >> a >> b;
		if (a + b > n - 2) {
			cout << -1 << endl;
			continue;
		}
		if (max(a, b) > (n - 1) / 2) {
			cout << -1 << endl;
			continue;
		}
		if (abs(a - b) > 1) {
			cout << -1 << endl;
			continue;
		}
		int l = 1, r = n;
		int c = 1;
		if (b > a)
			c = 2;
		VI R(n);
		FOR(i,0,a) {
			R[c] = r;
			r --;
			c += 2;
		}
		c = 2;
		if (b > a)
			c = 1;
		FOR(i,0,b) {
			R[c] = l;
			l ++;
			c += 2;
		}
		if (a > b)
			RFOR(i,n,0) {
			if (R[i] == 0) {
					R[i] = l;
					l ++;
				}
			}
		FOR(i,0,n) {
			if (R[i] == 0) {
				R[i] = l;
				l ++;
			}
		}
		// set<int> S;
		// FOR(i,0,n) {
		// 	S.insert(R[i]);
		// }
		// int ca = 0;
		// int cb = 0;
		// FOR(i,1,n - 1) {
		// 	if (R[i] > R[i - 1] && R[i] > R[i + 1])
		// 		++ ca;
		// 	if (R[i] < R[i - 1] && R[i] < R[i + 1])
		// 		++ cb;
		// }
		// cout << ca << ' '<< cb << endl;
		// if (S.size() != n || *S.begin() != 1 || *S.rbegin() != n || ca != a || cb != b) {
		// 	cout << "FAIL" << endl;
		// }
		FOR(i,0,n) {
			cout << R[i] << ' ';
		}
		cout << endl;
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}