#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int qzh[1000005];
long long pre[1000005];

long long fendge(int l,int r){
	if(l>=r){
		return 0;
	}
	int m=(l+r)>>1;
	long long ans=fendge(l,m)+fendge(m+1,r);
	qzh[m]=0;
	pre[m]=0;
	for(int i=m+1;i<=r;i++){
		qzh[i]=max(qzh[i-1],a[i]);
		pre[i]=pre[i-1]+qzh[i];
	}
	int ff=m,mx=0;
	for(int i=m;i>=l;i--){
		mx=max(mx,a[i]);
		while(qzh[ff]<mx&&ff<=r){
			ff++;
		}
		ans+=pre[r]-pre[ff-1]+1ll*mx*(ff-m-1);
	}
	qzh[m]=0x3f3f3f3f;
	pre[m]=0;
	for(int i=m+1;i<=r;i++){
		qzh[i]=min(qzh[i-1],a[i]);
		pre[i]=pre[i-1]+qzh[i];
	}
	ff=m,mx=0x3f3f3f3f;
	for(int i=m;i>=l;i--){
		mx=min(mx,a[i]);
		while(qzh[ff]>mx&&ff<=r){
			ff++;
		}
		ans-=pre[r]-pre[ff-1]+1ll*mx*(ff-m-1);
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	printf("%lld\n",fendge(1,n));
	return 0;
}