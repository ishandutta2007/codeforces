#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 30005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int T,n,m,c,q;
int p[MN];
int f[MN][5],sum[MN][5];//sum:
int g[MN][5],h[MN][5];//g: h:
vector<pii >ans,W[MN][5];
void solve(int st,int i,int j,int c){
	if(st>i)return;
	if(f[n][c]<j)return;
	int l=st-1,r=n+1;
	while(l+1<r){
		int mid=(l+r)>>1;	
		int now=j-sum[mid-1][c]+sum[st-1][c],use=0,ok=0;//oknow
		if(now<1){r=mid;continue;}
		if(now>g[mid][c]&&now<=h[mid][c]){l=mid;continue;}
		for(auto x:W[mid][c]){
			use=x.y;
			if(now<=f[n-(mid+x.y)][c-x.y]){ok=1; break;}
			now-=f[n-(mid+x.y)][c-x.y];	
		}
		if(ok&&use){
			if(use)ans.push_back(mp(mid,mid+use));
			solve(mid+use+1,i,now,c-use);
			return;
		}
		if(!ok)r=mid;
		else l=mid;
	}
	assert(r==n+1);
}
signed main(){
	T=read();
	for(int i=0;i<=4;++i)f[0][i]=1;
	for(int i=1;i<=30000;++i)
		for(int j=0;j<=4;++j){
			for(int k=0;k<=j&&k<i;++k){
				f[i][j]=(f[i][j]+f[i-k-1][j-k]);
			}
		}
	while(T--){
		n=read();c=read();q=read();
		for(int i=1;i<=n;++i)p[i]=read();
		for(int mid=1;mid<=n;++mid){	
			vector<pii> w;
			for(int k=0;k<=c&&mid+k<=n;++k){
				w.push_back(mp(p[mid+k],k));
			}
			sort(w.begin(),w.end());
			for(int k=0;k<=c;++k){
				W[mid][k].clear();	
				g[mid][k]=h[mid][k]=0;
				int ok=0;
				for(auto i:w){
					if(i.y<=k){
						W[mid][k].push_back(i);
						if(i.y==0){
							ok=1;
							h[mid][k]+=f[n-mid-i.y][k-i.y];
						}
						if(!ok){
							g[mid][k]+=f[n-mid-i.y][k-i.y];
							h[mid][k]+=f[n-mid-i.y][k-i.y];
						}
					}
				}
			}
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=c;++j){
				sum[i][j]=sum[i-1][j];
				for(int k=1;k<=j&&i+k<=n;++k)
					if(p[i]>p[i+k]){
						sum[i][j]+=f[n-i-k][j-k];	
					}
			}
		while(q--){
			int i=read(),j=read();
			if(f[n][c]<j){puts("-1");continue;}
			ans.clear();
			solve(1,i,j,c);
			bool ok=0;
			for(auto w:ans){
				if(w.x<=i&&i<=w.y){
					printf("%lld\n",p[w.y-(i-w.x)]);
					ok=1;
				}
			}
			if(!ok)printf("%lld\n",p[i]);
		}
	}
	return 0;
}