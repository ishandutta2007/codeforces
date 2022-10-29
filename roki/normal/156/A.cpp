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

string s;
string u;

bool read()
{
	if (!(cin >> s))
		return false;
	cin >> u;
	return true;
}

void solve()    
{
	int ans = u.size();
	string cur;
	forn (i, u.size())
		cur += '#';
	s = cur + s + cur;
	forn (i, s.size() - (int)u.size() + 1)
	{
		int tmp = u.size();
		forn (j, u.size())
			if (s[i + j] == u[j])
				tmp--;
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
	while (read())
		solve();
    return 0;
}