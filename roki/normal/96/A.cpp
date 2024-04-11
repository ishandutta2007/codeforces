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

string s;

bool read()
{
	if (!(cin >> s))
		return false;
    return true;
}

void solve()    
{
	forn (i, (int)s.size())
	{
		int j = i;
		while (j < s.size() && s[j] == s[i])
			j++;
		if (j - i >= 7)
		{
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    while(read())
        solve();
    return 0;
}