#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

map<int, int> p, sz, path;

pair<int, int> getp(int x)
{
	if (!p.count(x))
		return {x, 0};
	auto mem = getp(p[x]);
	mem.second ^= path[x];
	path[x] = mem.second;
	p[x] = mem.first;
	return mem;
}

void unite(int a, int b, int edge)
{
	auto p1 = getp(a), p2 = getp(b);;
	a = p1.first;
	b = p2.first;
	edge ^= p1.second ^ p2.second;
	assert(a != b);
	if (!sz[a])
		sz[a] = 1;
	if (!sz[b])
		sz[b] = 1;
	if (sz[a] < sz[b])
		swap(a, b);
	sz[a] += sz[b];
	path[b] = edge;
	p[b] = a;
}

int get(int l, int r)
{
	if (getp(l).first != getp(r).first)
		return -1;
	return getp(l).second ^ getp(r).second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	int last = 0;
	while (q--)
	{
		 int t;
		 cin >> t;
		 if (t == 1)
		 {
			 int l, r, x;
			 cin >> l >> r >> x;
			 l ^= last;
			 r ^= last;
			 x ^= last;
			 if (l > r)
				 swap(l, r);
			 ++r;
			 int x1 = get(l, r);
			 if (x1 == -1)
				 unite(l, r, x);
			 //cerr << getp(l).first << ' ' << getp(r).first << '\n';
			 //cerr << getp(l).second << ' ' << getp(r).second << '\n';
		 }
		 else
		 {
			 int l, r;
			 cin >> l >> r;
			 l ^= last, r ^= last;
			 if (l > r)
				 swap(l, r);
			 ++r;
			 int ans = get(l, r);
			 cout << ans << '\n';
			 if (ans == -1)
				 last = 1;
			 else
				 last = ans;
		 }
	}
	return 0;
}