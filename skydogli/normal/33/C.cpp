#include<bits/stdc++.h>
using namespace std;
int n,a[100005],suf[100005],sum,ans,now;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	int now=0;
	for(int i=n;i;--i){
		now+=((-a[i])*2);
		suf[i]=max(suf[i+1],now);
	}
	ans=max(ans,sum+suf[1]);
//	cout<<"HI "<<sum<<endl;
	for(int i=1;i<=n;++i){
		sum+=(-a[i])*2;
		ans=max(ans,sum+suf[i+1]);
//		cout<<i<<": "<<suf[i+1]<<endl;
	}
	printf("%d",ans);
}