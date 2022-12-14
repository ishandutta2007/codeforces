#include <bits/stdc++.h>
using namespace std;
#define M 300001

typedef long long ll;
int sto[M], a[M];
int f[M], g[M], bit[M];
int st[M], BIT[M];

int calc(int x){
	int res = 0;
	while(x) {
		res += bit[x];
	 	x -= x & -x;
	}
	return res;
}

void add(int x, int val) {
    while(x < M) {
		bit[x] += val;
		x += x & -x;
    }
}

void ADD(int x) {
	while(x < M) {
		BIT[x] += 1;
		x += x & -x;
	}
}

int CALC(int x) {
	int res = 0;
	while(x){
		res += BIT[x];
		x -= x & -x;
	}
	return res;
}


int main() {
	///freopen("5.in", "r", stdin);
	int n;
	ll k;
	scanf("%d %I64d", &n, &k);
	int m = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), sto[m ++] = a[i];
	sort(sto, sto + m);
	m = unique(sto, sto + m) - sto;
	for(int i = 1; i <= n; i ++) a[i] = lower_bound(sto, sto + m, a[i]) - sto + 1;
	for(int i = 0; i < M; i ++) bit[i] = 0;
	for(int i = 1; i <= n; i ++) {
        int x = calc(a[i]);
		f[i] = x;
		add(a[i], 1);
	}
	for(int i = 0; i < M; i ++) bit[i] = 0;
	for(int i = n; i; i --) {
		int x = calc(a[i] - 1);
		g[i] = x;
		add(a[i], 1);
	}
	///for(int i = 1; i <= n ; i ++) printf("%d ", g[i]);puts("");
	///for(int i = 1; i <= n ; i ++) printf("%d ", a[i]);puts("");
	ll sum = 0;
	for(int i = 1; i <= n; i ++) sum += g[i];
    if(sum <= k) {printf("%I64d\n", 1ll * n * (n - 1) / 2); return 0;}
	ll x = 0, ans = 0;
	for(int i = n; i; i --){
		ll y = x;
        if(a[i] < a[1]) x ++;
        x += g[i];
        if(x > k) {st[1] = i + 1; x = y; break;}
	}
	for(int i = 0; i < M; i ++) bit[i] = 0;
	for(int i = st[1]; i <= n; i ++) add(a[i], 1);
	ans = n - st[1] + 1;
	for(int i = 0; i < M; i ++) BIT[i] = 0;
	ADD(a[1]);
	///printf("%I64d\n", x);
	///printf("%d\n", st[1]);
    for(int i = 2; i < n; i ++) {
		ADD(a[i]);
        st[i] = st[i-1];
        x += calc(a[i] - 1);
        ///printf("calc(%d) = %d\n", a[i] - 1,  calc(a[i] - 1));
        x += (i - 1 - f[i]);
		///printf("%I64d\n", x);
        while(x > k && st[i] <= n) {
           ///x -= (a[i] > a[st[i]]);
            x -= g[st[i]];
            x -= (i - CALC(a[st[i]]));
            ///printf("calc = %d\n", i - calc(a[st[i]] - 1));
            add(a[st[i]], -1);
            st[i] ++;
        }
        if(st[i] > n) break;
        ///printf("i = %d st = %d x = %I64d\n", i, st[i], x);
        ans += n - st[i] + 1;
    }
    cout << ans << endl;
}