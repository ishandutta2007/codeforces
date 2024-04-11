#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MN 1000005
#define int long long
int n,k,a[MN],b[MN],sum[MN];
LL ans,ANS;
signed main(){
	scanf("%I64d%I64d",&n,&k);
	for(int i=1;i<=n;++i)a[i]=i,b[i]=n-i+1;
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+i;
	int l=1,r=n;
	LL ans=n*(n+1)/2;
	if(ans>k){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n/2;++i){
		ans+=(r-l);
		if(ans>k){
//			ans-=r;ans+=i;
			ans-=(r-l);
			while(l<r){
				if(ans+(r-l)<=k){
					swap(a[l],a[r]);
					ans+=r-l;
					//cout<<"? "<<ans<<endl;
					break;
				}
				l++;
			}
			break;
		}
		swap(a[l],a[r]);
		l++;r--;
	}
	printf("%I64d\n",ans);
	for(int i=1;i<=n;++i)printf("%I64d ",i);
	puts("");
	for(int i=1;i<=n;++i)printf("%I64d ",a[i]);
	return 0;
}