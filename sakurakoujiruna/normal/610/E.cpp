#include <iostream>
#include <cstring>
using namespace std;

typedef long long intl;
const int N = 301111;
const int K = 10;

struct Char_segment_tree
{
	int l[N << 2];
	int r[N << 2];
	int c[N << 2];
	int flag[N << 2];
	Char_segment_tree() { }
	void init(int left, int right, int* num, int x = 1)
	{
		l[x] = left;
		r[x] = right;
		flag[x] = -1;
		if(left + 1 != right)
		{
			int mid = (left + right) >> 1;
			init(left, mid, num, 2 * x);
			init(mid, right, num, 2 * x + 1);
		}
		else
			c[x] = num[left];
	}
	void push(int x)
	{
		if(flag[x] == -1)
			return;
		c[x] = flag[x];
		if(l[x] + 1 != r[x])
		{
			flag[2 * x] = flag[x];
			flag[2 * x + 1] = flag[x];
		}
		flag[x] = -1;
	}
	void change(int left, int right, int c, int x = 1)
	{
		push(x);
		if(l[x] == left && r[x] == right)
			flag[x] = c;
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
		push(x);
		if(l[x] + 1 == r[x])
			return c[x];
		int mid = (l[x] + r[x]) >> 1;
		if(mid > pos)
			return query(pos, 2 * x);
		else
			return query(pos, 2 * x + 1);
	}
}cst;

struct Gap_segment_tree
{
	int l[N << 2];
	int r[N << 2];
	int cnt[N << 2][K][K];
	int flag[N << 2][2];
	Gap_segment_tree() { }
	void init(int left, int right, int x = 1)
	{
		l[x] = left;
		r[x] = right;
		flag[x][0] = flag[x][1] = -1;
		memset(cnt[x], 0, sizeof(cnt[x]));
		if(left + 1 != right)
		{
			int mid = (left + right) >> 1;
			init(left, mid, 2 * x);
			init(mid, right, 2 * x + 1);
		}
	}
	void push(int x)
	{
		if(flag[x][0] == -1)
			return;
		memset(cnt[x], 0, sizeof(cnt[x]));
		int t0 = flag[x][0];
		int t1 = flag[x][1];
		cnt[x][t0][t1] = r[x] - l[x];
		if(l[x] + 1 != r[x])
		{
			flag[2 * x][0] = t0;
			flag[2 * x][1] = t1;
			flag[2 * x + 1][0] = t0;
			flag[2 * x + 1][1] = t1;
		}
		flag[x][0] = -1;
		flag[x][1] = -1;
	}
	void change(int left, int right, int t0, int t1, int x = 1)
	{
		/*
		if(x == 1)
			cout << left << ' ' << right << ' ' << t0 << ' ' << t1 << '\n';
		*/
		push(x);
		if(l[x] == left && r[x] == right)
		{
			flag[x][0] = t0, flag[x][1] = t1;
			push(x);
		}
		else
		{
			int mid = (l[x] + r[x]) >> 1;
			if(right <= mid)
			{
				change(left, right, t0, t1, 2 * x);
				push(2 * x + 1);
			}
			else if(left >= mid)
			{
				push(2 * x);
				change(left, right, t0, t1, 2 * x + 1);
			}
			else
			{
				change(left, mid, t0, t1, 2 * x);
				change(mid, right, t0, t1, 2 * x + 1);
			}
			for(int i = 0; i < K; i ++)
				for(int j = 0; j < K; j ++)
					cnt[x][i][j] = cnt[2 * x][i][j] + cnt[2 * x + 1][i][j];
		}
	}
	void query(int left, int right, int ans[K][K], int x = 1)
	{
		push(x);
		if(left == l[x] && right == r[x])
			for(int i = 0; i < K; i ++)
				for(int j = 0; j < K; j ++)
					ans[i][j] += cnt[x][i][j];
		else
		{
			int mid = (left + right) >> 1;
			if(right <= mid)
				query(left, right, ans, 2 * x);
			else if(left >= mid)
				query(left, right, ans, 2 * x + 1);
			else
			{
				query(left, mid, ans, 2 * x);
				query(mid, right, ans, 2 * x + 1);
			}
		}
	}
}gst;

int num[N];

int pos[K];
int cnt[K][K];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	string str;
	cin >> str;
	for(int i = 1; i <= n; i ++)
		num[i] = str[i - 1] - 'a';
	cst.init(1, n + 1, num);
	if(n != 1)
	{
		gst.init(1, n);
		for(int i = 1; i < n; i ++)
			gst.change(i, i + 1, num[i], num[i + 1]);
	}
	
	
	while(m --)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int l, r;
			char c;
			cin >> l >> r >> c;
			int t = c - 'a';
			
			if(n != 1)
			{
				if(l != r)
					gst.change(l, r, t, t);
				
				if(l != 1)
					gst.change(l - 1, l, cst.query(l - 1), t);
				if(r != n)
					gst.change(r, r + 1, t, cst.query(r + 1));
				cst.change(l, r + 1, t);
				//cout << t << '\n';
			}
		}
		else
		{
			string str;
			cin >> str;
			if(n != 1)
			{
				for(int i = 0; i < str.size(); i ++)
					pos[str[i] - 'a'] = i;
				intl len = 0;
				memset(cnt, 0, sizeof(cnt));
				gst.query(1, n, cnt);
				cnt[str[k - 1] - 'a'][cst.query(1)] ++;
				for(int i = 0; i < k; i ++)
					for(int j = 0; j < k; j ++)
					{
						if(cnt[i][j] != 0)	
						{
							if(pos[i] < pos[j])
								len += (pos[j] - pos[i]) * cnt[i][j];
							else
								len += (k + (pos[j] - pos[i])) * cnt[i][j];
							//cout << i << ' ' << j << ' ' << len << '\n';
						}
					}
				//cout << len << '\n';
				cout << (len - 1) / k + 1 << '\n';
			}
			else
				cout << 1 << '\n';
		}
	}
	
	return 0;
}