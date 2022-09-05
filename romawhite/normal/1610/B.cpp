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
const int MAX = 1007;
const int MOD = 998244353;

bool check(VI A, int x) {
	VI B;
	FOR(i,0,SZ(A))
		if (A[i] != x)
			B.push_back(A[i]);
	FOR(i,0,SZ(B)) {
		if (B[i] != B[SZ(B) - 1 - i])
			return false;
	}	
	return true;

}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n;
		cin >> n;
		VI A(n);

		FOR(i,0,n)	
			cin >> A[i];
		int x = -1;
		int y = -1;
		FOR(i,0,n) {
			if (A[i] != A[n - 1 - i]) {
				x = A[i];
				y = A[n - 1 - i];
				break;
			}
		}
		if (x == -1) {
			cout << "YES" << endl;
			continue;
		}
		if (check(A, x) || check(A, y)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}



    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}