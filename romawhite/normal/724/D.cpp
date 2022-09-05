#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:64000000")
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
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

string s;
int m;

int res[26];
int cnt[26];

void solve(int l, int r, char ch)
{
	//cout << l << ' ' << r << ' ' << ch << endl;

	if (l > r) return;
	bool ok = 1;
	VI A;
	A.push_back(l - 1);

	FOR(i,l,r + 2)
	{
		if (i != r + 1 && s[i] != ch) continue;

		if (i - A[SZ(A) - 1] > m) ok = 0;

		while (SZ(A) >= 2 && i - A[SZ(A) - 2] <= m) A.pop_back();
		A.push_back(i);
	}

	if (ok)
	{
		res[ch - 'a'] += SZ(A) - 2;
		return;
	}

	int last = l - 1;
	FOR(i,l,r + 1)
	{
		if (s[i] != ch) continue;
		solve(last + 1 , i - 1, ch + 1);
		last = i;
	}
	solve(last + 1 , r , ch + 1);

}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

    cin >> m >> s;
    FOR(i,0,SZ(s))
    {
    	cnt[s[i] - 'a'] ++;
    }

    solve(0,SZ(s) - 1 , 'a');

    int mx = 0;
    FOR(i,0,26)
    {
    	if (res[i])
    		mx = i;
    }

    FOR(i,0,mx)
    {
    	FOR(j,0,cnt[i])
    		cout << char('a' + i);
    }
    FOR(j,0,res[mx])
    {
    	cout << char('a' + mx);
    }

    return 0;
}