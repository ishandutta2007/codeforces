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
const int MAX = 200007;
const int MOD = 1000000007;

Int pw(Int a, int k) {
	Int res = 1;
	while (k) {
		if (k & 1) {
			res *= a;
			res %= MOD;
		}
		k /= 2;
		a *= a;
		a %= MOD;
	}
	return res;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	// t = 1;
	FOR(tt,0,t) {
		int n;
		cin >> n;
		VI A(n);
		FOR(i,0,n)
			cin >> A[i];
		
		sort(ALL(A));
		int res = 0;
		int ptr = 0;
		while(ptr < SZ(A)) {
			int add = 1;
			while (ptr + add < SZ(A) && A[ptr + add] == A[ptr])	++ add;
			int v = ptr + add;
			int cnt = add;
			// cout << "!!! " << ptr << ' ' << add << endl;
			while (v != n) {
				// cout << v << endl;
				int y = 2 * A[v] - A[ptr];
				v = lower_bound(ALL(A), y) - A.begin();
				++ cnt;
			}
			res = max(res, cnt);
			ptr += add;
		}
		cout << n - res << endl;

	}



    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}