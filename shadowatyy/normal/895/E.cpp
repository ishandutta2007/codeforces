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

const double eps = 1e-9;
const int M = 1<<17;

int n, q;

int a[M];

double mul[2*M];
double add[2*M];
double sub[2*M];

void push(int v, int l, int r)
{
	if(mul[v]>1+eps || mul[v]<1-eps)
	{
		sub[2*v] *= mul[v];
		sub[2*v+1] *= mul[v];
		mul[2*v] *= mul[v];
		mul[2*v+1] *= mul[v];
		add[2*v] *= mul[v];
		add[2*v+1] *= mul[v];
		mul[v] = 1;
	}

	if(add[v]>eps || add[v]<-eps)
	{
		sub[2*v] += add[v]*(r-l+1)/2;
		sub[2*v+1] += add[v]*(r-l+1)/2;
		add[2*v] += add[v];
		add[2*v+1] += add[v];
		add[v] = 0;
	}
}

void build(int v = 1, int l = 0, int r = M-1)
{
	mul[v] = 1;

	if(l==r)
	{
		sub[v] = a[l];
		return;
	}

	build(2*v, l, (l+r)/2);
	build(2*v+1, (l+r)/2+1, r);
	sub[v] = sub[2*v]+sub[2*v+1];
}

double query(int a, int b, int v = 1, int l = 0, int r = M-1)
{
	if(a>b || l>b || a>r)
		return 0;

	if(a<=l && r<=b)
		return sub[v];
	
	push(v, l, r);
	double ans = query(a, b, 2*v, l, (l+r)/2)+query(a, b, 2*v+1, (l+r)/2+1, r);
	sub[v] = sub[2*v]+sub[2*v+1];
	return ans;
}

void insert_mul(int a, int b, double c, int v = 1, int l = 0, int r = M-1)
{
	if(a>b || l>b || a>r)
		return;

	if(a<=l && r<=b)
	{
		sub[v] *= c;
		mul[v] *= c;
		add[v] *= c;
		return;
	}

	push(v, l, r);
	insert_mul(a, b, c, 2*v, l, (l+r)/2);
	insert_mul(a, b, c, 2*v+1, (l+r)/2+1, r);
	sub[v] = sub[2*v]+sub[2*v+1];
}

void insert_add(int a, int b, double c, int v = 1, int l = 0, int r = M-1)
{
	if(a>b || l>b || a>r)
		return;

	if(a<=l && r<=b)
	{
		sub[v] += (r-l+1)*c;
		add[v] += c;
		return;
	}

	push(v, l, r);
	insert_add(a, b, c, 2*v, l, (l+r)/2);
	insert_add(a, b, c, 2*v+1, (l+r)/2+1, r);
	sub[v] = sub[2*v]+sub[2*v+1];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	build();

	cout << fixed << setprecision(10);

	while(q--)
	{
		int t;
		cin >> t;

		if(t==1)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;

			double avgab = query(a, b)/(b-a+1);
			double avgcd = query(c, d)/(d-c+1);

			insert_mul(a, b, (double)(b-a)/(b-a+1));
			insert_mul(c, d, (double)(d-c)/(d-c+1));

			insert_add(a, b, (double)1/(b-a+1)*avgcd);
			insert_add(c, d, (double)1/(d-c+1)*avgab);
		}
		else
		{
			int a, b;
			cin >> a >> b;
			cout << query(a, b) << endl;
		}
	}
}