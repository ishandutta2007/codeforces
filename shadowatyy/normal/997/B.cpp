#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define int ll

int n, ans;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int a = 0; a <= 8; ++a)
	{
		for(int b = 0; b <= 48; ++b)
		{
			if(a+b<=n)
			{
				bool ok = 1;

				for(int c = 0; c <= 8; ++c)
				{
					for(int d = 0; d <= 48; ++d)
					{
						if(c+d<=n)
						{
							int x = 4*a+9*b-4*c-9*d;

							if(x>0 && x%49==0)
								ok = 0;
						}
					}
				}

				if(ok)
					ans += n-a-b+1;
			}
		}
	}

	cout << ans << endl;
}