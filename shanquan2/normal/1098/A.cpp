#include<bits/stdc++.h>
using namespace std;

int n,p[100005],a[100005],s[100005],b[100005];
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	for(int i=1;i<=n;i++){
		if(s[i]==-1)b[i]=(1<<30);
	}
	for(int i=n;i>=2;i--)if(s[i]!=-1){
		int u=p[i],v=p[u];
		if(s[i]<s[v]){
			printf("-1\n");
			return 0;
		}
		b[u]=min(b[u],s[i]-s[v]);
	}
	long long ans=s[1];
	a[1]=s[1];
	for(int i=2;i<=n;i++){
		int u=p[i];
		if(b[i]==(1<<30))b[i]=0;
		if(s[i]==-1)s[i]=s[u]+b[i];
		a[i]=s[i]-s[u];
		ans+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}