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

bool ok(li cur)
{
	int tot = 0;
	vector<int> cnt(10, 0);
	while (cur)
	{
		cnt[cur % 10]++;
		cur /= 10;
		tot++;
	}
	if (cnt[4] == cnt[7] && (cnt[4] << 1) == tot)
		return true;
	return false;
}

li f(int a, int b)
{
	li res = 0;
	forn (i, b)
	{
		res *= 10;
		if (a & (1 << i))
			res += 7;
		else
			res += 4;
	}
	return res;
}

void solve()    
{
	li ans = 1e15;
	li cur = 0;
		forn (i, s.size())
		{
			cur *= 10;
			cur += s[i] - '0';
		}
		for (int l = 2; l <= 12; l += 2)
			forn (i, 1 << l)
			{
				li k = f(i, l);
				if (ok(k) && k >= cur)
					ans = min(ans, k);
		}
		cout << ans << endl;
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