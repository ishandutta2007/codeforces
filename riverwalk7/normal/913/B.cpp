#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qwer1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

const int N = 1005;

using namespace std;

int n, cnt[N], p[N], res[N];
int c[12345678];

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	//~read
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		scanf("%d", &p[i]);
		cnt[p[i]]++;
	}
	for(int i=1; i<12345678; i++)
	{
	    c[i] = i*4-3;
	}
	//~solve
	forn(i, n)
	{
		if (!cnt[i])
			res[p[i]]++;
	}
	forn(i, n)
	{
		if (cnt[i] && res[i] < 3)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	return 0;
}