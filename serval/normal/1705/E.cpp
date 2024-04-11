#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int LIM = 2e5;
const int N = 4e5 + 5;
const long long oo = 1e6;

int n, q;
int a[N];
int cnt[N];

priority_queue <int> pq, pd;

int qtop()
{
	while (!pq.empty() && !pd.empty())
		if (pq.top() == pd.top())
		{
			pq.pop();
			pd.pop();
		}
		else
			break;
	return pq.top();
}

void qdel(int v) { pd.push(v); }
void qins(int v) { pq.push(v); }

struct state
{
	int rcnt, lreq, len;
	state(){}
	state(int rcnt, int lreq, int len)
	{
		this->rcnt = rcnt;
		this->lreq = lreq;
		this->len = len;
	}
};

state st[N << 1];

state merge(state l, state r)
{
	int rcnt, len;
	long long req;
	if (l.rcnt >= r.lreq)
	{
		r.rcnt++;
		l.rcnt -= r.lreq;
		r.lreq = (1 << min(20, r.len));
	}
	int v = l.rcnt >> min(20, r.len);
	r.rcnt += v;
	l.rcnt -= v << min(20, r.len);
	req = r.lreq - l.rcnt;
	req = ((req - 1) << min(20, l.len)) + l.lreq;
	req = min(req, oo);
	len = l.len + r.len;
	rcnt = r.rcnt;
	return state(rcnt, req, len);
}

void build(int u, int l, int r)
{
	if (l == r)
	{
		st[u] = state(0, 2, 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 ^ 1, mid + 1, r);
	st[u] = merge(st[u << 1], st[u << 1 ^ 1]);
}

void ins(int u, int l, int r, int p, int v)
{
	if (l == r)
	{
		st[u].rcnt += v;
		return;
	}
	int mid = (l + r) >> 1;
	if (p <= mid)
		ins(u << 1, l, mid, p, v);
	else
		ins(u << 1 ^ 1, mid + 1, r, p, v);
	st[u] = merge(st[u << 1], st[u << 1 ^ 1]);
}

state qry(int u, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr)
		return st[u];
	int mid = (l + r) >> 1;
	if (qr <= mid)
		return qry(u << 1, l, mid, ql, qr);
	if (ql > mid)
		return qry(u << 1 ^ 1, mid + 1, r, ql, qr);
	return merge(qry(u << 1, l, mid, ql, qr),
		qry(u << 1 ^ 1, mid + 1, r, ql, qr));
}

int main()
{
	scanf("%d%d", &n, &q);
	build(1, 1, LIM);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		cnt[a[i]]++;
		qins(a[i]);
		ins(1, 1, LIM, a[i], 1);
	}
	while (q--)
	{
		int k, l;
		scanf("%d%d", &k, &l);
		cnt[a[k]]--;
		qdel(a[k]);
		ins(1, 1, LIM, a[k], -1);
		a[k] = l;
		qins(a[k]);
		ins(1, 1, LIM, a[k], 1);
		cnt[a[k]]++;
		int mx = qtop();
		state qv = qry(1, 1, LIM, 1, mx);
		int cur = qv.rcnt, ans = mx;
		while (cur)
		{
			ans = max(ans, mx);
			cur /= 2;
			mx++;
		}
		printf("%d\n", ans);
	}
	return 0;
}