#include<bits/stdc++.h>
using namespace std;
struct cc{
	int s;
	int e;
}ss[100010];
bool cmp(cc a,cc b){
	return a.e<b.e;
}
int main()
{
	long long n,r,avg,ans=0,m=0,x=0;
	scanf("%lld%lld%lld",&n,&r,&avg);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&ss[i].s,&ss[i].e);
		m+=ss[i].s;
	}
	ans=avg*n-m;
	if(ans<=0){
		x=0;
	}else{
		sort(ss+1,ss+n+1,cmp);
		for(int i=1;i<=n;i++){
			int t=min(ans,r-ss[i].s);
			ans-=t;
			x+=1ll*ss[i].e*t;
			
			
//			while(ans>0&&ss[i].s<r){
//				
//				ans--;
//				ss[i].s++;
//				x+=ss[i].e;
//			}
			if(ans==0) break;
		}
	}
	printf("%lld",x);
	return 0;
}
// 2e9 2*10^9
// 4e18 4*10^18