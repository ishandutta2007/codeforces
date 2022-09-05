#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:160777216")
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
using namespace std;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
 
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
 
typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;
 
const int INF = 1000000000;
const int MAX = 4007;
const int MAX2 = 7000;
const int MOD = 1000000007;
 
vector<Int> a;

int main()
{
        #ifndef ONLINE_JUDGE
               // freopen("in.txt", "r", stdin);
        #endif
   
		//freopen("input.txt" , "r" , stdin);
		//freopen("output.txt" , "w", stdout);

		int n;
		cin >> n;
		FOR(i,0,n)
		{
			int x;
			scanf("%d" , &x);
			a.push_back(x);
		}

		sort(ALL(a));
		Int res = 0;
		FOR(i,0,a.size())
		{
			res += a[i] * (2 + i);
		}
		res -= a.back();

		cout << res << endl;
        return 0;
}