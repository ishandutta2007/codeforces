#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 211111;

struct Xor_segment_tree
{
	int l[N << 2];
	int r[N << 2];
	int num[N << 2];
	int lazy[N << 2];

	Xor_segment_tree() { }

	void initialize(int left, int right, int a[], int x = 1)
	{
		l[x] = left;
		r[x] = right;
		num[x] = 0;
		lazy[x] = 0;
		if(left + 1 == right)
			num[x] = a[left];
		else
		{
			int mid = (left + right) >> 1;
			initialize(left, mid, a, 2 * x);
			initialize(mid, right, a, 2 * x + 1);
		}
	}

	void push_lazy(int x)
	{
		if(l[x] + 1 == r[x])
			num[x] ^= lazy[x];
		else
		{
			lazy[2 * x] ^= lazy[x];
			lazy[2 * x + 1] ^= lazy[x];
		}
		lazy[x] = 0;
	}
	void change(int left, int right, int c, int x = 1)
	{
		push_lazy(x);
		if(left == l[x] && right == r[x])
			lazy[x] ^= c;
		else
		{
			int mid = (l[x] + r[x]) >> 1;
			if(mid >= right)
				change(left, right, c, 2 * x);
			else if(mid <= left)
				change(left, right, c, 2 * x + 1);
			else
			{
				change(left, mid, c, 2 * x);
				change(mid, right, c, 2 * x + 1); 
			}
		}
	}
	int query(int pos, int x = 1)
	{
		push_lazy(x);
		if(l[x] + 1 == r[x])
			return num[x];
		int mid = (l[x] + r[x]) >> 1;
		if(pos < mid)
			return query(pos, 2 * x);
		else
			return query(pos, 2 * x + 1);
	}
}xor_st;

vector <int> gauss_insert(vector <int> &v, int x)
{
	vector <int> ret = v;
	for(int i = 0; i < ret.size(); i ++)
		if(ret[i] & (-ret[i]) & x)
			x ^= ret[i];
	if(x == 0)
		return ret;
	for(int i = 0; i < ret.size(); i ++)
		if(x & (-x) & ret[i])
			ret[i] ^= x;
	ret.push_back(x);
	return ret;
}
vector <int> gauss_merge(const vector <int> &a, const vector <int> &b)
{
	vector <int> ret = a;
	for(int i = 0; i < b.size(); i ++)
		ret = gauss_insert(ret, b[i]);
	return ret;
}

struct Gauss_segment_tree
{
	int l[N << 2];
	int r[N << 2];
	vector <int> num[N << 2];

	Gauss_segment_tree() { }

	void initialize(int left, int right, int a[], int x = 1)
	{
		l[x] = left;
		r[x] = right;
		num[x].clear();
		if(left + 1 == right)
			if(a[left] != 0)
				num[x].push_back(a[left]);
			else { }
		else
		{
			int mid = (left + right) >> 1;
			initialize(left, mid, a, 2 * x);
			initialize(mid, right, a, 2 * x + 1);
			num[x] = gauss_merge(num[2 * x], num[2 * x + 1]);
		}
	}
	void change(int pos, int c, int x = 1)
	{
		if(l[x] + 1 == r[x])
		{
			num[x].clear();
			if(c != 0)
				num[x].push_back(c);
		}
		else
		{
			int mid = (l[x] + r[x]) >> 1;
			if(pos < mid)
				change(pos, c, 2 * x);
			else
				change(pos, c, 2 * x + 1);
			num[x] = gauss_merge(num[2 * x], num[2 * x + 1]);
		}
	}
	vector <int> query(int left, int right, int x = 1)
	{
		if(l[x] == left && r[x] == right)
			return num[x];
		int mid = (l[x] + r[x]) >> 1;
		if(mid >= right)
			return query(left, right, 2 * x);
		else if(mid <= left)
			return query(left, right, 2 * x + 1);
		else
			return gauss_merge(query(left, mid, 2 * x), query(mid, right, 2 * x + 1));
	}
}guass_st;

int a[N];
int b[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	b[1] = a[1];
	b[n + 1] = 0;
	for(int i = 2; i <= n; i ++)
		b[i] = (a[i - 1] ^ a[i]);

	xor_st.initialize(1, n + 1, a);
	guass_st.initialize(1, n + 2, b);

	while(q --)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int l, r, c;
			cin >> l >> r >> c;
			xor_st.change(l, r + 1, c);
			b[l] ^= c;
			b[r + 1] ^= c;
			guass_st.change(l, b[l]);
			guass_st.change(r + 1, b[r + 1]);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			if(l == r)
			{
				int tmp = xor_st.query(l);
				if(tmp == 0)
					cout << 1 << '\n';
				else
					cout << 2 << '\n';
			}
			else
			{
				vector <int> tmp = guass_st.query(l + 1, r + 1);
				tmp = gauss_insert(tmp, xor_st.query(l));
				cout << (1 << (tmp.size())) << '\n';
			}
		}
	}
	return 0;
}