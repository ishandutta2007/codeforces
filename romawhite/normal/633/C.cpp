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
const int MAX = 1000007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

struct state
{
	bool q;
	int next[26];
	state()
	{
		q = 0;
		FOR(i,0,26)
		{
			next[i] = -1;
		}
	}
};

state A[MAX];
int cnt = 1;

map<PII , string> M;

char buf[1007];

char lower(char ch)
{
	if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 'a';
	else return ch;
}

int dp[10007];
int p[10007];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n;
	cin >> n;
	string s;
	cin >> s;

	int m;
	cin >> m;
	FOR(i,0,m)
	{
		scanf("%s" , buf);
		string t = buf;
		Int H1 = 0;
		Int H2 = 0;
		string tt = t;
		FOR(i,0,tt.size())
		{
			tt[i] = lower(tt[i]);
		}
		RFOR(i,t.size(), 0)
		{
			H1 = (H1 * 1000003 + tt[i]) % MOD;
			H2 = (H2 * 997 + tt[i]) % (MOD + 2);
		}
		M[MP(H1 , H2)] = t;

		int cur = 0;
		RFOR(i,tt.size() , 0)
		{
			int x = tt[i] - 'a';
			if (A[cur].next[x] == -1)
			{
				A[cur].next[x] = cnt++;
			}
			cur = A[cur].next[x];
		}
		A[cur].q = 1;
	}

	dp[0] = 1;
	p[0] = -1;
	FOR(i,0,n)
	{
		if (dp[i])
		{
			int cur = 0;
			FOR(j,i, min(n , i + 1007))
			{
				int x = s[j] - 'a';
				if (A[cur].next[x] == -1) break;
				cur = A[cur].next[x];
				if (A[cur].q)
				{
					dp[j + 1] = 1;
					p[j + 1] = i;
				}
			}
		}
	}
	VI res;
	while (n != -1)
	{
		res.push_back(n);
		n = p[n];
	}

	reverse(ALL(res));
	FOR(i,0,res.size() - 1)
	{
		Int H1 = 0;
		Int H2 = 0;
		FOR(j,res[i] , res[i + 1])
		{
			H1 = (H1 * 1000003 + s[j]) % MOD;
			H2 = (H2 * 997 + s[j]) % (MOD + 2);
		}
		cout << M[MP(H1 , H2)] << ' ';
	}
	cout << endl;

    return 0;
}