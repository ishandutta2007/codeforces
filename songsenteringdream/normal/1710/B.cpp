#include<cstdio>
#include<algorithm>
using namespace std;
const int o=2e5+10,inf=2e9+10;
int T,n,m,x[o],p[o],X[o],cnt,lg[o];long long b1[o],b2[o];
struct ST{
	long long st[o][20];
	inline void build(){
		for(int i=1;i<20;++i) for(int j=1;j<=cnt;++j)
			if(j+(1<<(i-1))<=cnt) st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);else st[j][i]=st[j][i-1];
	}
	inline long long query(int l,int r){if(l>r) return -1e18;int t=lg[r-l+1];return max(st[l][t],st[r-(1<<t)+1][t]);}
}st1,st2,st3;
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%d%d",&n,&m);cnt=n;lg[0]=-1;
		for(int i=1;i<=n;++i) scanf("%d%d",&x[i],&p[i]),X[i]=x[i];
		sort(X+1,X+n+1);cnt=unique(X+1,X+n+1)-X-1;X[cnt+1]=inf;
		for(int i=1;i<=cnt;++i) b1[i]=b2[i]=0,lg[i]=lg[i>>1]+1;
		for(int i=1;i<=n;++i)
			++b1[lower_bound(X+1,X+cnt+1,x[i]-p[i])-X],--b1[lower_bound(X+1,X+cnt+1,x[i])-X],
			--b1[lower_bound(X+1,X+cnt+1,x[i])-X],++b1[upper_bound(X+1,X+cnt+1,x[i]+p[i])-X],
			b2[lower_bound(X+1,X+cnt+1,x[i]-p[i])-X]+=p[i]-x[i],b2[lower_bound(X+1,X+cnt+1,x[i])-X]-=p[i]-x[i],
			b2[lower_bound(X+1,X+cnt+1,x[i])-X]+=p[i]+x[i],b2[upper_bound(X+1,X+cnt+1,x[i]+p[i])-X]-=p[i]+x[i];
		for(int i=1;i<=cnt;++i)
			b1[i]+=b1[i-1],b2[i]+=b2[i-1],
			st1.st[i][0]=b1[i]*1ll*X[i]+b2[i],st2.st[i][0]=st1.st[i][0]-X[i],st3.st[i][0]=st1.st[i][0]+X[i];
		st1.build();st2.build();st3.build();
		for(int i=1;i<=n;++i)
			putchar(48+(st1.query(1,lower_bound(X+1,X+cnt+1,x[i]-p[i])-X-1)<=m&&st1.query(upper_bound(X+1,X+cnt+1,
			x[i]+p[i])-X,cnt)<=m&&st2.query(lower_bound(X+1,X+cnt+1,x[i]-p[i])-X,lower_bound(X+1,X+cnt+1,x[i])-X)
			-p[i]+x[i]<=m&&st3.query(lower_bound(X+1,X+cnt+1,x[i])-X,upper_bound(X+1,X+cnt+1,x[i]+p[i])-X-1)-p[i]-x[i]<=m));
	}
	return 0;
}