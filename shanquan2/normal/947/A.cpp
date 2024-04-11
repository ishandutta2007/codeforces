#include<bits/stdc++.h>
using namespace std;

const int N=1000005;
int ans,n,a[N];
bool vis[N];
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++)a[i]=N;
	int t=0;
	for(int i=2;i<=n;i++)if(!vis[i]){
		for(int j=i+i;j<=n;j+=i){
			vis[j]=1;
			a[j]=min(a[j],j-i+1);
			if(j==n)t=max(i,t);
		}
	}
	ans=N;
	for(int i=n-t+1;i<=n;i++)ans=min(ans,a[i]);
	printf("%d\n",ans);
	return 0;
}