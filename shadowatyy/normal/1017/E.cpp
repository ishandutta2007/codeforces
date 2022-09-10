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
const int N = 3e5+7;

int n, m;

tuple<int, int, int> A[N];

int kmp[N];

struct pkt
{
	int x, y;
};

vector<pkt> a, b;

bool comp(pkt a, pkt b)
{
	if(a.x==b.x)
		return a.y<b.y;
	else
		return a.x<b.x;
}

bool prawo(pkt a, pkt b, pkt c)
{
	return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y)>0;
}

int wek(pkt a, pkt b, pkt c)
{		
	return (a.x-b.x)*(c.y-b.y)-(c.x-b.x)*(a.y-b.y);
}

int ska(pkt a, pkt b, pkt c)
{
	return (a.x-b.x)*(c.x-b.x)+(a.y-b.y)*(c.y-b.y);
}

int len(pkt a, pkt b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

vector<pkt> hull(vector<pkt> v)
{
	sort(ALL(v), comp);

	vector<pkt> u, l;

	for(auto it:v)
	{
		while(u.size()>=2 && !prawo(u[u.size()-2], u.back(), it))
			u.pop_back();

		u.pb(it);
	}

	reverse(ALL(v));

	for(auto it:v)
	{
		while(l.size()>=2 && !prawo(l[l.size()-2], l.back(), it))
			l.pop_back();

		l.pb(it);
	}

	u.pop_back();
	l.pop_back();
	u.insert(u.end(), ALL(l));
	return u;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		int x, y;
		cin >> x >> y;
		a.pb((pkt){x, y});
	}		

	for(int i = 1; i <= m; ++i)
	{
		int x, y;
		cin >> x >> y;
		b.pb((pkt){x, y});
	}

	a = hull(a);
	b = hull(b);

	if(a.size()!=b.size())
	{
		cout << "NO" << endl;
		return 0;
	}

	n = a.size();

	for(int i = 0; i < n; ++i)
	{
		A[i+1] = {ska(a[i%n], a[(i+1)%n], a[(i+2)%n]), wek(a[i%n], a[(i+1)%n], a[(i+2)%n]), len(a[i%n], a[(i+1)%n])};
	}	

	for(int i = 0; i < 2*n; ++i)
	{
		A[i+1+n+1] = {ska(b[i%n], b[(i+1)%n], b[(i+2)%n]), wek(b[i%n], b[(i+1)%n], b[(i+2)%n]), len(b[i%n], b[(i+1)%n])};
	}

	int q = 0;

	for(int i = 2; i <= 3*n+1; ++i)
	{
		while(q && A[q+1]!=A[i])
			q = kmp[q];

		if(A[q+1]==A[i])
			++q;

		kmp[i] = q;

		if(kmp[i]==n)
		{
			cout << "YES" << endl;
			exit(0);
		}
	}

	cout << "NO" << endl;
}