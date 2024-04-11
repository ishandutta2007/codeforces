#include<bits/stdc++.h>
using namespace std;
const int maxn = 200010;
char s[maxn], t[maxn];
int sm[maxn * 4], cov[maxn * 4];
void build(int x, int l, int r){
    cov[x] = -1;
    if (l == r) {
        sm[x] = t[l] - '0';
        return;    
    }
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    sm[x] = sm[x << 1] + sm[x << 1| 1];
}
int A;
void get(int x, int l, int r, int pl, int pr) {
    if (pl <= l && pr >= r){
        A += sm[x];
        return;
    }
    int mid = l + r >> 1;
    if (cov[x] != -1){
        cov[x<<1] = cov[x << 1|1] = cov[x];
        if (cov[x] == 0) sm[x<<1] = sm[x<<1|1] = 0;
        else sm[x<<1] = mid - l + 1, sm[x<<1|1] = r - mid ;
        cov[x] = -1;
    }
    if (pl <= mid) get(x << 1, l , mid, pl, pr);
    if (pr > mid) get(x << 1 | 1, mid + 1, r, pl, pr);
    sm[x] = sm[x << 1] + sm[x << 1 | 1];
}
void Cov(int x, int l, int r, int pl, int pr, int val) {
    if(pl <= l && pr >= r)
	{
		sm[x] = (r - l + 1) * val;
		cov[x] = val;
		return;
	}
	int mid = l + r >> 1;
	if (cov[x] != -1){
        cov[x<<1] = cov[x << 1|1] = cov[x];
        if (cov[x] == 0) sm[x<<1] = sm[x<<1|1] = 0;
        else sm[x<<1] = mid - l + 1, sm[x<<1|1] = r - mid;
        cov[x] = -1;
    }
	if(pl <= mid)	Cov(x << 1, l, mid, pl, pr, val);
	if(pr > mid)	Cov(x << 1 | 1, mid + 1, r, pl, pr, val);
	sm[x] = sm[x << 1] + sm[x << 1 | 1];
}
int n;
bool Check()
{
	bool ok=1;
    for (int i = 1; i <= n; i++) {
        A = 0;
        get(1, 1, n, i, i);
        if (A != s[i] - '0') return 0;
    }
	return 1;
}
int l[maxn], r[maxn];
void solve(){
    int q;
    cin >> n >> q;
    scanf("%s%s", s + 1, t + 1);
    build(1, 1, n);
    for (int i = 1; i <= q; i++) scanf("%d%d", &l[i], &r[i]);
	bool flag = 0;
	for (int i = q; i >= 1 && !flag; i--)
    {
		int num = r[i] - l[i] + 1;
        A = 0;
		get(1, 1, n, l[i], r[i]);
        //printf("=== %d %d\n",i, A);
		A <<= 1;
        if(A  > num)
            Cov(1, 1, n, l[i], r[i], 1);
        else if(A < num)
            Cov(1, 1, n, l[i], r[i], 0);
		else flag = 1;
	}
    if (!flag){
        puts(Check()?"YES":"NO");
    }
	else
        puts("NO");
}
int main(){
    int t;
    cin >> t;
    while (t--) solve();
}