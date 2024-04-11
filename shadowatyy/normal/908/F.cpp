#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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

#define int long long
const int N = 3e5+7;

int n, ans, cnt;

int p[N];
int c[N];
int w[N];

int solve(int l, int r)
{
	if(c[l] || c[r])
		return 2*(p[r]-p[l]);

	int hr = 0, hb = 0, lr = inf, lb = inf;

	for(int i = l; i <= r; ++i)
	{
		if(c[i]!=2)
		{
			hr = max(hr, p[i]-lr);
			lr = p[i];
		}	
		
		if(c[i]!=1)
		{
			hb = max(hb, p[i]-lb);
			lb = p[i];
		}
	}

	return min(3*(p[r]-p[l])-hr-hb, 2*(p[r]-p[l]));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];

		char t;
		cin >> t;

		if(t=='G')
			c[i] = 0;
		else if(t=='R')
			c[i] = 1;
		else if(t=='B')
			c[i] = 2;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!c[i])
			w[++cnt] = i;
	}

	int fr = -1, fb = -1, lr = -1, lb = -1;

	for(int i = 1; i <= n; ++i)
	{
		if(c[i]==1)
		{
			if(fr==-1)
				fr = p[i];

			lr = p[i];
		}
		else if(c[i]==2)
		{
			if(fb==-1)
				fb = p[i];

			lb = p[i];
		}
	}

	if(cnt==0)
	{
		cout << lr-fr+lb-fb;
		exit(0);
	}

	if(fr!=-1)
	{
		ans += max(0ll, p[w[1]]-fr);
		ans += max(0ll, lr-p[w[cnt]]);
	}

	if(fb!=-1 )
	{
		ans += max(0ll, p[w[1]]-fb);
		ans += max(0ll, lb-p[w[cnt]]);
	}
	
	for(int i = 1; i < cnt; ++i)
	{
		ans += solve(w[i], w[i+1]);
	}

	cout << ans;
}