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
const int MAX = 200007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

UInt PR1 = 1000003;
UInt PR2 = 1000000007;

UInt Hash(string s)
{
	s += '#';
	UInt h = 0;
	FOR(i,0,s.size())
	{
		h = h * PR1 + s[i];
	}
	return h;
}

map<string, vector<UInt> > M;

map<UInt, vector<string> > R;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n;
	cin >> n;

	FOR(i,0,n)
	{
		string s;
		cin >> s;
		string t = "";
		string u = "";
		int cnt = 0;
		FOR(j,0,s.size())
		{
			if (s[j] == '/') ++cnt;
			if (cnt < 3)
			{
				t += s[j];
			}
			else
			{
				u += s[j];
			}
		}

		M[t].push_back(Hash(u));
	}
	for(map<string, vector<UInt> >::iterator it = M.begin(); it != M.end(); ++it)
	{
		sort(ALL(it->second));
		it->second.resize(unique(ALL(it->second)) - it->second.begin());
		UInt h = 0;
		FOR(i,0,it->second.size())
		{
			h = h * PR2 + it->second[i];
		}
		R[h].push_back(it->first);
	}

	int t = 0;
	for(map<UInt, vector<string> >::iterator it = R.begin(); it != R.end(); ++it)
	{
		if (it->second.size() <= 1) continue;
		++t;
	}
	cout << t << endl;
	for(map<UInt, vector<string> >::iterator it = R.begin(); it != R.end(); ++it)
	{
		if (it->second.size() <= 1) continue;
		FOR(i,0,it->second.size())
		{
			cout << it->second[i] << ' ';
		}
		cout << endl;
	}

    return 0;
}