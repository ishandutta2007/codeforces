#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<cassert>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

int n;
int b[200000];
int a[200000];
int m;

bool read()
{
	if (!(cin >> n))
		return false;
	forn (i, n)
		cin >> b[i];
	cin >> m;
    return true;
}

int nt[200000];

int next(int v)
{
	if (v == n - 1)
		return v;
	return a[v] < b[v] ? v : nt[v] = next(nt[v]);
}

void solve()    
{
	forn (i, 200000)
		nt[i] = i + 1;
	forn (i, m)
	{
		int t, c;
		cin >> t >> c;
		c--;
		if (t == 1)
		{
			int cap;
			cin >> cap;
			while (true)
			{
				c = next(c);
				int cur = min(cap, b[c] - a[c]);
				a[c] += cur;
				cap -= cur;
				if (cap == 0 || c == n - 1)
					break;
			}
		}
		else
			cout << a[c] << endl;
	}
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
	read();
	solve();
    return 0;
}