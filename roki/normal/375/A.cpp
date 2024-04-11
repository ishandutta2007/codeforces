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

char c[1000000];
int a[1000000];

bool read()
{
	gets(c);
	return true;
}

void solve()    
{
	int n = strlen(c);
	int sz = 0;
	vector<bool> used(10, false);
	forn (i, n)
		if ((c[i] == '1' || c[i] == '6' || c[i] == '8' || c[i] == '9') && !used[c[i] - '0'])
			used[c[i] - '0'] = true;
		else
			a[sz++] = c[i] - '0';
	vector<int> v(4);
	v[0] = 1, v[1] = 6, v[2] = 8, v[3] = 9;
	do
	{
		int tmp = 0;
		forn (i, 4)
		{
			tmp = (tmp * 10) % 7;
			tmp += v[i];
		}
		forn (i, sz - 1)
		{
			tmp *= 10;
			tmp = (tmp + a[i]) % 7;
		}
		tmp *= 3;
		tmp = (tmp + a[sz - 1]) % 7;
		if (tmp == 0)
		{
			forn (i, 4)
				cout << v[i];
			forn (i, sz)
				printf("%d", a[i]);
			cout << endl;
			return;
		}
	}while (next_permutation(all(v)));
	cout << 0 << endl;
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