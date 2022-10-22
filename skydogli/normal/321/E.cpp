#include<bits/stdc++.h>
using namespace std;
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 4005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int n,k,f[MN],g[MN],sum[MN][MN];
int w(int i,int j){
//	cerr<<"sum "<<i<<" "<<j<<": "<<sum[j][j]-sum[i-1][j]-sum[i][j-1]+sum[i-1][j-1]<<endl;;
//	cerr<<"??? "<<sum[j][j]<<" "<<sum[i-1][j]<<" "<<sum[i][j-1]<<" "<<sum[i-1][i-1]<<endl;
	return sum[j][j]-sum[i-1][j]-sum[j][i-1]+sum[i-1][i-1];
}
void solve(int l,int r,int pl,int pr){
	if(l>r)return;
//	cerr<<"solve: "<<l<<" "<<r<<" "<<pl<<" "<<pr<<endl;
	if(pl==pr){
		for(int j=l;j<=r;++j)g[j]=f[pl]+w(pl+1,j);
		return;
	}
	int mid=(l+r)>>1,pos=0;
	for(int i=pl;i<=pr&&i<mid;++i){
		if(g[mid]>f[i]+w(i+1,mid))g[mid]=f[i]+w(i+1,mid),pos=i;
	}
	solve(l,mid-1,pl,pos);
	solve(mid+1,r,pos,pr);
}
signed main(){
	n=read();k=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+read();
		}
	for(int i=1;i<=n;++i)f[i]=g[i]=1e9;
	for(int i=1;i<=k;++i){
		solve(1,n,0,n-1);
//		cerr<<"now : "<<i<<endl;
		for(int i=1;i<=n;++i){
			f[i]=g[i],g[i]=1e9;
//			cerr<<"f "<<i<<": "<<f[i]<<endl;
		}
	}
	printf("%d\n",f[n]>>1);
	return 0;
}