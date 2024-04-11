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
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
#define mn 105
int T,n,m,k,q;
int b[mn][mn],fk[mn][mn],ans[mn];
int tot;
pii id[MN];
bool cmp(pii x,pii y){return b[x.x][x.y]<b[y.x][y.y];}
signed main(){
	T=read();
	while(T--){
		n=read();m=read();
		tot=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j){
				b[i][j]=read();
				id[++tot]=mp(i,j);
			}
		sort(id+1,id+1+tot,cmp);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)fk[i][j]=0;
		for(int i=1;i<=m;++i){
			fk[id[i].x][id[i].y]=i;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)ans[j]=0;
			for(int j=1;j<=m;++j){
				if(fk[i][j])ans[fk[i][j]]=b[i][j];
			}
			for(int j=1;j<=m;++j)
				if(!fk[i][j])
					for(int k=1;k<=m;++k)
						if(!ans[k]){
							ans[k]=b[i][j];break;
						}
			for(int j=1;j<=m;++j)printf("%lld ",ans[j]);
			puts("");
		}
	}
	return 0;
}