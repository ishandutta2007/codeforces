#include <bits/stdc++.h>

using ll = long long;

const int max_N = 1e5 + 21;

int n,v[max_N],t[max_N];

ll T[max_N],ans[max_N];

int cnt[max_N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",v+i);
	for(int i=1;i<=n;++i)scanf("%d",t+i);
	for(int i=1;i<=n;++i)T[i]=T[i-1]+t[i];
	for(int i=1;i<=n;++i){
		int pos=std::upper_bound(T+1,T+1+n,T[i-1]+v[i])-T-1;
		++cnt[i],--cnt[pos+1];
		ans[pos+1]+=T[i-1]+v[i]-T[pos];
	}
	for(int i=1;i<=n;++i)cnt[i]+=cnt[i-1];
	for(int i=1;i<=n;++i)ans[i]+=1ll*cnt[i]*t[i];
	for(int i=1;i<=n;++i)printf("%lld%c",ans[i]," \n"[i==n]);
	return 0;
}