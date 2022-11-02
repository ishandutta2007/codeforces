#include<bits/stdc++.h>
using namespace std;

#define N 201000
typedef long long ll;

long long  n, m, k, a[N], b[N], c[N], d[N], x, s, ind[N], start, pos;
long long ans;

bool cmp(long long  l,long long r){
	return b[l] > b[r];
}


main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	scanf("%I64d%I64d",&x,&s);
	for(ll i = 0;i < m;i ++) scanf("%I64d",a + i), ind[i] = i;
	for(ll i = 0;i < m;i ++) scanf("%I64d",b + i);
	for(ll i = 0;i < k;i ++) scanf("%I64d",c + i);
	for(ll i = 0;i < k;i ++) scanf("%I64d",d + i);
	sort(ind,ind + m, cmp);
	ans = 1ll * x * n;
	for(ll i = 0;i < m;i ++){
		if(b[ind[i]] > s) continue;
		ans = min(ans,1ll*a[ind[i]] * n);
		while(1){
			if(b[ind[i]] + d[pos + 1] > s || pos == k - 1) break;
			pos ++;
		}
		if(s < b[ind[i]] + d[pos]) continue;
		ll t = (n - c[pos]) * (n > c[pos]);
		ans = min(ans,1ll * a[ind[i]] * t);
	}
	for(ll i = 0;i < k;i ++){
		if(s < d[i]) break;
		ans = min(ans, x * (n - c[i]) * (n > c[i]));
	}
	printf("%I64d",ans);
}