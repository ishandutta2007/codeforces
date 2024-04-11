#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define pb push_back
#define maxn 400019
#define maxs
#define maxnode
#define ls ch[o][0]
#define rs ch[o][1]
#define M 
#define Hash
#define Base 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define mem(x, v) memset(x, sizeof(x), v)
using namespace std;

int n, m;
pii a[maxn];
int b[maxn], ans[maxn];
vector<pii> q[maxn];

int sum[maxn << 2];
void add(int l, int r, int o, int x){
	sum[o]++;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	if (x <= mid) add(l, mid, o << 1, x);
	else add(mid + 1, r, o << 1 | 1, x);
}
int get(int l, int r, int o, int k){
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l;
	if (sum[o << 1] >= k) return get(l, mid, o << 1, k);
	else return get(mid + 1, r, o << 1 | 1, k - sum[o << 1]);
}

int main(){
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i].fi), b[i] = a[i].fi, a[i].se = i, a[i].fi = -a[i].fi;
	sort(a + 1, a + 1 + n);
	scanf("%d", &m);
	int k, pos;
	rep(i, 1, m) scanf("%d%d", &k, &pos), q[k].pb(pii(pos, i));
	rep(k, 1, n){
		add(1, n, 1, a[k].se);
		int si = q[k].size();
		srep(i, 0, si) ans[q[k][i].se] = b[get(1, n, 1, q[k][i].fi)]; 
	}
	rep(i, 1, m) printf("%d\n", ans[i]);
	return 0;
}