#include<bits/stdc++.h>
using namespace std;
int ans,T,i,j,n,k,vis[1005],rr,l[1004],r[1004];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(i=1;i<=n+n;++i)vis[i]=0;
		for(i=1;i<=k;++i)cin>>l[i]>>r[i],vis[l[i]]=vis[r[i]]=1;
		ans=(n-k)*(n-k-1)/2;
		for(i=1;i<=k;++i){
			if(l[i]>r[i])swap(l[i],r[i]);
			rr=0;
			for(j=l[i]+1;j<r[i];++j)rr+=(vis[j]==0);
			ans+=min(rr,(n+n-k-k-rr));
		}
		for(i=1;i<=k;++i){
			for(j=1;j<i;++j){
				if((l[i]<l[j]&&r[i]>l[j]&&r[i]<r[j])||(l[j]<l[i]&&r[j]>l[i]&&r[j]<r[i]))++ans;
			}
		}
		cout<<ans<<"\n";
	}
}