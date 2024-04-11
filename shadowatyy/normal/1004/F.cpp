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

bool xd;

#define cerr if(xd)cerr

#define int ll
const int N = 1<<17;

int n, m, x;

int a[N];

struct typ
{
	int ile = 0;
	VPII lewo;
	VPII prawo;
};

typ T[2*N];

void merge_lewo(typ &v, typ &u, typ &w)
{
	int a = 0;
	int b = 0;
	bitset<20> vis;

	while(a<u.lewo.size() || b<w.lewo.size())
	{
		if(a<u.lewo.size() && (b==w.lewo.size() || u.lewo[a]<w.lewo[b]))
		{
			if(!vis[u.lewo[a].nd])
			{
				v.lewo.pb(u.lewo[a]);
				vis[u.lewo[a].nd] = 1;
			}

			++a;
		}
		else
		{
			if(!vis[w.lewo[b].nd])
			{
				v.lewo.pb(w.lewo[b]);
				vis[w.lewo[b].nd] = 1;
			}

			++b;
		}
	}
}

void merge_prawo(typ &v, typ &u, typ &w)
{
	int a = 0;
	int b = 0;
	bitset<20> vis;

	while(a<u.prawo.size() || b<w.prawo.size())
	{
		if(a<u.prawo.size() && (b==w.prawo.size() || u.prawo[a]>w.prawo[b]))
		{
			if(!vis[u.prawo[a].nd])
			{
				v.prawo.pb(u.prawo[a]);
				vis[u.prawo[a].nd] = 1;
			}

			++a;
		}
		else
		{
			if(!vis[w.prawo[b].nd])
			{
				v.prawo.pb(w.prawo[b]);
				vis[w.prawo[b].nd] = 1;
			}

			++b;
		}
	}
}

typ merge(typ &u, typ &w, int lu, int ru, int lw, int rw)
{
	typ v;
	v.ile = u.ile+w.ile;
	int b = -1;
	int L = 0, R = 0;

	for(auto it:u.prawo)
	{
		L |= 1<<it.nd;
	}

	for(int a = u.prawo.size(); a >= 0; --a)
	{
		if(a!=u.prawo.size())
		{
			L ^= 1<<u.prawo[a].nd;
		}

		while((L|R)<x && b+1<w.lewo.size())
		{
			++b;
			R |= 1<<w.lewo[b].nd;
		}

		if((L|R)>=x)
		{
			int len_u = -1;

			if(u.prawo.empty())
				len_u = ru-lu+1;
			else if(a==u.prawo.size())
				len_u = u.prawo.back().st-lu+1;
			else if(a==0)
				len_u = ru-u.prawo[a].st;
			else
				len_u = u.prawo[a-1].st-u.prawo[a].st;

			int len_w = -1;

			if(b==-1)
				len_w = rw-lw+1;
			else
				len_w = rw-w.lewo[b].st+1;

			if(len_u*len_w)
			{
				v.ile += len_u*len_w;
			}
		}
	}

	merge_lewo(v, u, w);
	merge_prawo(v, u, w);
	return v;
}

void build(int v = 1, int l = 0, int r = N-1)
{
	if(l==r)
	{
		for(int i = 0; i < 20; ++i)
		{
			if(a[l]&(1<<i))
			{
				T[v].prawo.eb(l, i);
				T[v].lewo.eb(l, i);
			}
		}

		T[v].ile = (a[l]>=x);
		return;
	}

	build(2*v, l, (l+r)/2);
	build(2*v+1, (l+r)/2+1, r);
	T[v] = merge(T[2*v], T[2*v+1], l, (l+r)/2, (l+r)/2+1, r);
}

void insert(int a, int c, int v = 1, int l = 0, int r = N-1)
{
	if(l==r)
	{
		T[v].ile = (c>=x);
		T[v].lewo.clear();
		T[v].prawo.clear();

		for(int i = 0; i < 20; ++i)
		{
			if(c&(1<<i))
			{
				T[v].lewo.eb(l, i);
				T[v].prawo.eb(l, i);
			}
		}

		return;
	}

	if(a<=(l+r)/2)
		insert(a, c, 2*v, l, (l+r)/2);
	else
		insert(a, c, 2*v+1, (l+r)/2+1, r);

	T[v] = merge(T[2*v], T[2*v+1], l, (l+r)/2, (l+r)/2+1, r);
}

typ query(int a, int b, int v = 1, int l = 0, int r = N-1)
{
	if(a<=l && r<=b)
		return T[v];

	if(b<=(l+r)/2)
		return query(a, b, 2*v, l, (l+r)/2);
	else if(a>(l+r)/2)
		return query(a, b, 2*v+1, (l+r)/2+1, r);
	else
	{
		auto L = query(a, b, 2*v, l, (l+r)/2);
		auto R = query(a, b, 2*v+1, (l+r)/2+1, r);
		return merge(L, R, max(a, l), (l+r)/2, (l+r)/2+1, min(b, r));
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> x;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	build();

	while(m--)
	{
		int t;
		cin >> t;

		if(t==1)
		{
			int i, y;
			cin >> i >> y;
			insert(i, y);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << query(l, r).ile << endl;
		}
	}
}