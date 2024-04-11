
                #define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
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
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 100007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n;
	cin >> n;
	VI f(n);
	set<int> s;
	FOR(i,0,n)
	{
		scanf("%d" , &f[i]);
		-- f[i];
		if (f[i] == i)
		{
			s.insert(i);
		}
	}

	FOR(i,0,n)
	{
		if (s.find(f[i]) == s.end())
		{
			cout << -1 << endl;
			return 0;
		}
	}

	int m = SZ(s);

	map<int, int> M;

	VI h;
	for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		M[*it] = SZ(h);
		h.push_back(*it);
	}



	VI g;
	FOR(i,0,n)
	{
		g.push_back(M[f[i]]);
	}

	cout << m << endl;
	FOR(i,0,n)
	{
		printf("%d " , g[i] + 1);
	}
	cout << endl;
	FOR(i,0,m)
	{
		printf("%d " , h[i] + 1);
	}
	cout << endl;



    return 0;
}