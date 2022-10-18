#include <bits/stdc++.h>
#define endl '\n'
 
#define int long long
 
using namespace std;
const int MAXN = (int)3e5 + 42;
 
int n, m;
int a[MAXN];
 
struct node
{
	int apref, asuff, l, r, len, pref[2], suff[2], ans, lazy;
 
	node() {apref = 0; asuff = 0; len = 0; l = 0; r = 0; ans = 0; pref[0] = 0; suff[0] = 0; pref[1] = 0; suff[1] = 0; lazy = 0;}
	node(int val)
	{
		l = val;
		r = val;
		pref[0] = 1;
		suff[0] = 1;
		pref[1] = 1;
		suff[1] = 1;
		ans = 1;
		len = 1;
		lazy = 0;
		apref = 1;
		asuff = 1;
	}
};
 
node temp, broken;
 
node merge(node l, node r)
{
	temp.ans = max(l.ans, r.ans);
	temp.len = l.len + r.len;
	temp.l = l.l;
	temp.r = r.r;
 
    if(l.r < r.l) temp.ans = max(l.suff[0] + r.apref, temp.ans);
    if(l.r > r.l) temp.ans = max(l.asuff + r.pref[1], temp.ans);
 
    temp.pref[0] = l.pref[0];
    if(l.r < r.l && temp.pref[0] == l.len) temp.pref[0] += r.pref[0];
 
    temp.pref[1] = l.pref[1];
    if(l.r > r.l && temp.pref[1] == l.len) temp.pref[1] += r.pref[1];
 
    temp.suff[0] = r.suff[0];
    if(l.r < r.l && temp.suff[0] == r.len) temp.suff[0] += l.suff[0];
 
    temp.suff[1] = r.suff[1];
    if(l.r > r.l && temp.suff[1] == r.len) temp.suff[1] += l.suff[1];
 
    temp.apref = l.apref;
    temp.asuff = r.asuff;
 
    if(l.r > r.l && r.suff[1] == r.len)
        temp.asuff = l.asuff + r.suff[1];
    if(l.r < r.l && r.asuff == r.len)
        temp.asuff = l.suff[0] + r.asuff;
 
    if(l.r > r.l && l.apref == l.len)
        temp.apref = l.apref + r.pref[1];
    if(l.r < r.l && l.pref[0] == l.len)
        temp.apref = l.pref[0] + r.apref;
 
	temp.lazy = 0;
 
	temp.ans = max(temp.ans, temp.asuff);
	temp.ans = max(temp.ans, temp.apref);
 
	return temp;
}
 
struct segment_tree
{
	node tr[4 * MAXN];
 
	void push(int l, int r, int idx)
	{
		if(tr[idx].lazy)
		{
            tr[idx].l += tr[idx].lazy;
            tr[idx].r += tr[idx].lazy;
 
			if(l != r)
			{
				tr[2 * idx + 1].lazy += tr[idx].lazy;
				tr[2 * idx + 2].lazy += tr[idx].lazy;
			}
 
			tr[idx].lazy = 0;
		}
	}
 
	void init(int l, int r, int idx)
	{
		if(l == r)
		{
			tr[idx] = node(a[l]);
			return;
		}
 
		int mid = (l + r) >> 1;
		init(l, mid, 2 * idx + 1);
		init(mid + 1, r, 2 * idx + 2);
 
		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
	}
 
	void update(int qL, int qR, int val, int l, int r, int idx)
	{
		push(l, r, idx);
 
		if(qL > r || l > qR)
			return;
 
		if(qL <= l && r <= qR)
		{
			tr[idx].lazy += val;
			push(l, r, idx);
			return;
		}
 
		int mid = (l + r) >> 1;
		update(qL, qR, val, l, mid, 2 * idx + 1);
		update(qL, qR, val, mid + 1, r, 2 * idx + 2);
 
		tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
    }
 
	node query(int qL, int qR, int l, int r, int idx)
	{
		push(l, r, idx);
 
		if(l > qR || r < qL)
			return broken;
 
		if(qL <= l && r <= qR)
			return tr[idx];
 
		int mid = (l + r) >> 1;
		return merge(query(qL, qR, l, mid, 2 * idx + 1), query(qL, qR, mid + 1, r, 2 * idx + 2));
	}
};
 
void read()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
}
 
segment_tree t;
 
void solve()
{
    t.init(1, n, 0);
 
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int l, r, val;
        cin >> l >> r >> val;
        t.update(l, r, val, 1, n, 0);
        cout << t.query(1, n, 1, n, 0).ans << endl;
    }
}
 
#undef int
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	read();
	solve();
	return 0;
}