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
using namespace std;

const int N = 3e5+7;
const int M = 1<<19;

int n, a, b, c, d, start, len;

int t[N];
int q[N];

int Min[N];
int Max[N];

ll p1[N];
ll p2[N];

struct tree
{
	ll load[2*M];

	void insert(int a, ll v)
	{
		a += M;
		load[a] = v;
		a /= 2;

		while(a>=1)
		{
			load[a] = min(load[2*a], load[2*a+1]);
			a /= 2;
		}
	}

	ll query(int a, int b)
	{
		if(a>b)
			return INF;

		a += M;
		b += M;

		ll res = min(load[a], load[b]);

		while(a<b-1)
		{
			if(a%2==0)
				res = min(res, load[a+1]);
			
			if(b%2==1)
				res = min(res, load[b-1]);

			a /= 2;
			b /= 2;
		}

		return res;
	}
};	

tree T1, T2;

bool sprawdz(int a, int b)
{
	if(T1.query(0, a-1)<0)
		return 0;

	if(T2.query(a, b)-p2[a-1]+p1[a-1]<0)
		return 0;

	//if(T1.query(b+1, n)-(p1[b]-p1[a-1])+(p2[b]-p2[a-1])<0)
	//	return 0;

	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> a >> b >> c >> d >> start >> len;

	p1[0] = p2[0] = start;
	t[0] = -1;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i] >> q[i];

		if(q[i])
		{
			p1[i] = a;
			p2[i] = c;
		}
		else
		{
			p1[i] = -b;
			p2[i] = -d;
		}

		p1[i] += p1[i-1];
		p2[i] += p2[i-1];
	}

	int r = 1;

	for(int l = 1; l <= n; ++l)
	{
		while(r<n && t[r+1]-t[l]+1<=len)
			++r;

		Max[l] = r;
	}

	r = 1;

	for(int l = 1; l <= n; ++l)
	{
		while(r<n && t[r+1]-(t[l-1]+1)+1<=len)
			++r;

		Min[l] = r;
	}

	for(int i = 0; i <= n; ++i)
	{
		T1.insert(i, p1[i]);
		T2.insert(i, p2[i]);
	}

	//if(T1.query(1, n)>=0 && t[1]>=len)
	if(t[1]>=len)
	{
		cout << 0;
		return 0;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = Min[i]; j <= Max[i]; ++j)
		{
			if(sprawdz(i, j))
			{
				cout << max(t[i-1]+1, t[j]-len+1);
				return 0;
			}
		}
	}

	if(T1.query(1, n)>=0)
	{
		cout << t[n]+1;
		return 0;
	}

	cout << -1;
}