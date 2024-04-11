#include <bits/stdc++.h>
#define ll long long int 
#define maxn 300019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

int n;
int p[maxn];
ll k;
int x, a, y, b, d; //x > y

int gcd(int x, int y){
	return (!y) ? x : gcd(y, x % y);
}

bool judge(int num){	
	int A = num / ((ll)a * b / d);
	int B = num / a - A;
	int C = num / b - A;
	ll ans = 0;
	per(i, n, n - A + 1){	
		ans += (ll)p[i] / 100 * (x + y);
	}
	per(i, n - A, n - A - B + 1){
		ans += (ll)p[i] / 100 * x;
	}
	per(i, n - A - B, n - A - B - C + 1){
		ans += (ll)p[i] / 100 * y;
	}
	return (ans >= k);
}
int solve(int l, int r){	
	if (l == r) return (l == n + 1) ? -1 : l;
	int mid = ((r - l) >> 1) + l;
	if (judge(mid)) return solve(l, mid);
	else return solve(mid + 1, r);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &p[i]);
		sort(p + 1, p + 1 + n);
		scanf("%d%d", &x, &a);
		scanf("%d%d", &y, &b);
		d = gcd(a, b);
		if (x < y) swap(x, y), swap(a, b);
		scanf("%lld", &k);
		printf("%d\n", solve(1, n + 1));
	}
	return 0;
}