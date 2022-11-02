#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 5e5+10;

ll n,k,c[N],ans,sum;

inline int cmp(ll x,ll y){
	return x > y;
}

int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i <= n;i++) scanf("%lld",&c[i]);
	sort(c+1,c+1+n,cmp);
	if(!k){
		for(int i=1;i <= n;i++) ans += sum , sum += c[i];
		printf("%lld\n",ans);
		return 0;
	}
	int x=1;
	for(;x <= n;x++){
		ans += sum , sum += c[x];
		if(sum < 0) break;
	}
	c[x] = sum , sum = 0;
	ll cnt=0;
//	sort(c+1+x,c+1+n,cmp);
	for(int i=n;i >= x;i--){
		ans += c[i]*(cnt/(k+1));
		cnt++;
	}
	printf("%lld\n",ans);
	return 0;
}