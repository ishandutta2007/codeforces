#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 1, A = 1e6 + 1;

int prime[A], len;
bool vis[A];

int t, n, e, a[N];
long long ans;

int main(){
	for(int i = 2; i < A; i++){
		if(!vis[i])
			prime[++len] = i;
		for(int j = 1; j <= len && i * prime[j] < A; j++){
			vis[i * prime[j]] = true;
			if(i % prime[j] == 0)
				break;
		}
	}
	scanf("%d", &t);
	while(t--){
		ans = 0;
		scanf("%d%d", &n, &e);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for(int i = 1; i <= e; i++){
			int l = i, p = i, r = i;
			while(l <= n && p <= n && r <= n){
				while(l <= n && a[l] != 1 && vis[a[l]])
					l += e;
				p = max(p, l);
				while(p <= n && a[p] == 1)
					p += e;
				if(p > n || vis[a[p]]){
					l = p + e;
					continue;
				}
				r = p;
				while(r + e <= n && a[r + e] == 1)
					r += e;
				if(r <= n){
					ans += 1ll * ((r - p) / e + 1) * ((p - l) / e + 1) - 1;
				}
				l = p + e;
				p = r + e;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}