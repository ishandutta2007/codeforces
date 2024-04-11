#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VLL = vector<ll>;
using PII = pair<int, int>;
using VPII = vector<PII>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

#define int ll

int n, ans;

int cnt[2][2];

string a, b;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> a >> b;

	for(int i = 0; i < n; ++i)
	{
		++cnt[a[i]-'0'][b[i]-'0'];
	}

	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			for(int k = 0; k < 2; ++k)
			{
				for(int l = 0; l < 2; ++l)
				{
					int teraz = 0, potem = 0;

					if(i || j)
						teraz += 1;

					if(k || l)
						teraz += 2;

					if(k || j)
						potem += 1;

					if(l || i)
						potem += 2;

					if(teraz!=potem)
					{
						if(i!=k || j!=l)
							ans += cnt[i][j]*cnt[k][l];
						else
							ans += cnt[i][j]*(cnt[i][j]-1);
					}
				}
			}
		}
	}

	cout << ans/2 << endl;
}