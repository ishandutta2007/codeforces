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
#define MN 20005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int T,n,m,q;
int a[MN];
int f[15][31][MN],st[15][MN];
int Log[MN],g[31];
int _max(int i,int j){return (a[i]+i<a[j]+j)?j:i;}
int askmx(int l,int r){
	if(l>r)return 0;
//	cerr<<"? "<<l<<" "<<r<<endl;
	int lg=Log[r-l+1];
	return _max(st[lg][l],st[lg][r-(1<<lg)+1]);
}
signed main(){
	n=read();q=read();
	Log[0]=-1;for(int i=1;i<=n;++i)Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;++i){
		a[i]=min(read(),n-i);
		st[0][i]=i;
	}
	memset(f,0x3f,sizeof(f));
	for(int j=0;j<=30;++j)
		for(int i=1;i<=n;++i){
			f[0][j][i]=min(i+a[i]+j,n);
		}
	for(int i=1;i<=14;++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			st[i][j]=_max(st[i-1][j],st[i-1][j+(1<<i-1)]);
	for(int i=1;i<=14;++i){
		for(int k=0;k<=30;++k){
			if(k)for(int j=1;j+(1<<i)-1<=n;++j)f[i][k][j]=f[i][k-1][j];
			else for(int j=1;j+(1<<i)-1<=n;++j)f[i][k][j]=0;
			for(int l=0;l<=k;++l){
				for(int j=1;j+(1<<i)-1<=n;++j){
					int r=f[i-1][l][j];
					int p=askmx(j,r);
					f[i][k][j]=max(f[i][k][j],min(f[i-1][k-l][p],n));
				}
			}
		}
	}
	while(q--){
		int l=read(),r=read(),k=read();
		if(l==r){puts("0");continue;}
		int now=0;
		for(int i=0;i<=k;++i)g[i]=l;
		int ans=n;
		for(int i=14;i>=0;--i){
			bool ok=0;
			for(int j=0;j<=k;++j){
				if(f[i][k-j][askmx(l,g[j])]>=r){
					ans=min(ans,now+(1<<i));ok=1;	
					break;
				}
			}
			if(!ok){
				now+=(1<<i);
				for(int j=k;j>=0;--j){
					int p=askmx(l,g[j]);
					g[j]=max(g[j],f[i][0][p]);
					for(int o=0;o<j;++o){
						int p=askmx(l,g[o]);
						g[j]=max(g[j],f[i][j-o][p]);
					}
					assert(g[j]<r);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}