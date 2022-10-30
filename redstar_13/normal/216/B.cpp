#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
typedef pair <int,int> pii;
int n,m,r,dp,k;
#define NN 110
int f[NN],vst[NN],a[NN],b[NN];
int dfs(int x){
	for(int i=1;i<=m;i++){
		if(a[i]==x and vst[b[i]]) return dp;
		if(b[i]==x and vst[a[i]]) return dp;
		if(a[i]==x and b[i]!=r) {
			k=b[i];
			vst[k]=1;
			dp++;
			a[i]=0;
			b[i]=0;
			dfs(k);
		}
		if(b[i]==x and a[i]!=r) {
			k=a[i];
			vst[k]=1;
			dp++;
			a[i]=0;
			b[i]=0;
			dfs(k);
		}
		if(i==m) return 0;
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",a+i,b+i),f[a[i]]=1,f[b[i]]=1; 
	int y=0;
	for(int i=1;i<=n;i++) if(!f[i]) y++;
	int s=0;
	for(int i=1;i<=n;i++){
		if(f[i]==0) continue;
		if(vst[i]) continue;
		vst[i]=1;
		r=i;
		dp=1;
		int k=dfs(i);
		cerr<<k<<endl;
		if(k%2) s++;
	}
	int t=(n-s)/2;
	cout<<n-2*t<<endl;
	return 0;
}