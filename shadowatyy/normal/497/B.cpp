#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) (int)(x).size()
using namespace std;

const int N = 1e5+7;

int n;

int a[N];
int b[N];

VPII res;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		int w;
		cin >> w;

		if(w==1)
			++a[i];
		else
			++b[i];

		a[i] += a[i-1];
		b[i] += b[i-1];
	}

	for(int t = 1; t <= n; ++t)
	{
		int A = 0, B = 0, curr = 0, last = -1;

		while(curr!=n)
		{
			int l = curr+1, r = n;

			while(l<r)
			{
				int m = (l+r)/2;

				if(m==r)
					--m;

				if(max(a[m]-a[curr], b[m]-b[curr])>=t)
					r = m;
				else
					l = m+1;
			}

			if(max(a[l]-a[curr], b[l]-b[curr])!=t)
			{
				curr = -1;
				break;
			}

			if(a[l]-a[curr]==t)
			{
				++A;
				last = 1;
			}
			else
			{
				++B;
				last = 2;
			}
			
			curr = l;
		}

		if(curr!=-1)
		{
			if(A>B && last==1)
				res.eb(A, t);
			else if(B>A && last==2)
				res.eb(B, t);
		}
	}

	sort(ALL(res));

	cout << res.size() << endl;

	for(auto it:res)
		cout << it.st << " " << it.nd << endl;
}