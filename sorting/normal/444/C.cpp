#include<bits/stdc++.h>

using namespace std;

const long long MAXN = 1e5 + 7;

struct node
{
	long long sum, col, lazy;

	node()
	{
		sum = 0;
		col = -2;
		lazy = 0;
	}

	node(long long _col, long long _sum)
	{
		col = _col;
		sum = _sum;
		lazy = 0;
	}
};

node temp, broken;

node merge(node l, node r)
{
	if(l.col == -2)
		return r;
	if(r.col == -2)
		return l;

	temp.lazy = 0;
	temp.col = (l.col == r.col) ? l.col : -1;
	temp.sum = l.sum + r.sum;

	return  temp;
}

struct  segment_tree
{
	node tr[4*MAXN];

	void push(long long l, long long r, long long idx)
	{
		tr[idx].sum += tr[idx].lazy * (r - l + 1);

		if(l != r)
		{
			tr[2 * idx + 1].lazy += tr[idx].lazy;
			tr[2 * idx + 2].lazy += tr[idx].lazy;

			if(tr[idx].col != -1)
			{
				tr[2 * idx + 1].col = tr[idx].col;
				tr[2 * idx + 2].col = tr[idx].col;
			}
		}

		tr[idx].lazy = 0;
	}

	void init(long long l, long long r, long long idx)
	{
		if(l == r)
		{
			tr[idx] = node(l, 0);
			return;
		}

		long long mid = (l+r) >> 1;

		init(l, mid, 2 * idx + 1);
		init(mid + 1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}

	void update(long long qL, long long qR, long long nw_col, long long l, long long r, long long idx)
	{
		push(l, r, idx);

		//cout << l << " " << r << endl;

		if(qL <= l && r <= qR && tr[idx].col != -1)
		{
			tr[idx].lazy += abs(nw_col - tr[idx].col);
			tr[idx].col = nw_col;
			push(l, r, idx);

			return;
		}

		if(qL > r || l > qR)
			return;

		long long mid = (l + r) >> 1;

		update(qL, qR, nw_col, l, mid, 2 * idx + 1);
		update(qL, qR, nw_col, mid+1, r, 2 * idx + 2);

		tr[idx] = merge(tr[2 * idx + 1], tr[2*idx + 2]);
	}

	node query(long long qL, long long qR, long long l, long long r, long long idx)
	{
		push(l, r, idx);

		//cout << tr[idx].sum << " " << idx << endl;
		//cout << qL << " " << qR << " " << l << " " << r << endl;

		if(qL <= l && r <= qR)
			return tr[idx];

		if(qL > r || l > qR)
			return broken;

		long long mid = (l+r) >> 1;

		return merge(query(qL, qR, l, mid, 2 * idx +1), query(qL, qR, mid + 1, r, 2 * idx + 2));
	}
};

segment_tree st;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m;

	cin >> n >> m;

	st.init(1, n , 0);

	for(long long i = 0; i < m; i++)
	{
		long long type;

		cin >> type;

		if(type == 1)
		{
			long long l, r, x;

			cin >> l >> r >> x;

			st.update(l, r, x, 1, n, 0);
		}
		else
		{
			long long l, r;

			cin >> l >> r;

			cout << st.query(l, r, 1, n, 0).sum << "\n";
		}
	}

	return 0;
}