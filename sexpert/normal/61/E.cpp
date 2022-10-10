#include<bits/stdc++.h>
using namespace std;

struct node
{
	int l;
	int r;
	int val;
	node(int l = 0, int r = 0, int val = 0) : l(l), r(r), val(val){}
};

const int MAXN = 1000000;

struct SegmentTree
{
	node tree[4*MAXN + 5];
	int pos[MAXN + 5];

	void build(int l, int r, int id = 1)
	{
		tree[id] = node(l, r);
		if(l == r)
			pos[l] = id;
		else
		{
			build(l, (l + r)/2, 2*id);
			build((l + r)/2 + 1, r, 2*id + 1);
		}
	}

	void update(int lf, int value)
	{
		int id = pos[lf];
		tree[id].val = value;
		while(id > 0)
		{
			id /= 2;
			tree[id].val = tree[2*id].val + tree[2*id + 1].val;
		}
	}

	long long query(int l, int r, int id = 1)
	{
		node n = tree[id];
		if(r < n.l || n.r < l || l > r)
			return 0;
		if(l <= n.l && n.r <= r)
			return n.val;
		return query(l, r, 2*id) + query(l, r, 2*id + 1);
	}
};

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

bool compSnd(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	vector<int> a;
	SegmentTree left, right;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back({i, x});
	}
	sort(v.begin(), v.end(), compSnd);
	for(int i = 0; i < n; i++)
	{
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end(), comp);
	for(auto p : v)
		a.push_back(p.second);
	left.build(1, n);
	right.build(1, n);
	for(int x : a)
		right.update(x, 1);
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		right.update(a[i], 0);
		//cout << left.query(3, n) << endl;
		//cout << a[i] << " " << left.query(a[i] + 1, n) << " " << right.query(1, a[i] - 1) << " " << left.query(1, n) << endl;
		ans += left.query(a[i] + 1, n)*right.query(1, a[i] - 1);
		left.update(a[i], 1);
		/*for(int j = 1; j < 4*n; j++)
		{
			node nd = left.tree[j];
			cout << nd.l << " " << nd.r << " " << nd.val << endl;
		}*/
	}
	cout << ans << endl;
}