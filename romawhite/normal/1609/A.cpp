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
const int MAX = 300007;
const int MOD = 1000000007;

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n;
		cin >> n;
		vector<Int> A(n);
		int cnt = 0;
		FOR(i,0,n) {
			cin >> A[i];
			while(A[i] % 2 == 0) {
				cnt ++;
				A[i] /= 2;
			}
		}
		sort(ALL(A));
		FOR(i,0,cnt) {
			A.back() *= 2;
		}
		Int res = 0;
		FOR(i,0,SZ(A))
			res += A[i];
		cout << res << endl;
	}
	
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}