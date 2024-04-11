#include<cstdio>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
#define double long double
const int o=2e5+10;const double eps=1e-12,PI=acosl(-1);
int n,m,nxt[o][20];double ans=1e18;long long X[o],Y[o];pair<double,double> p[o];
inline bool chk(double r){
	for(int i=1;i<=n;++i){
		p[i].second=atan2(Y[i],X[i])-acos(r/sqrt(X[i]*X[i]+Y[i]*Y[i]));
		p[i].first=atan2(Y[i],X[i])+acos(r/sqrt(X[i]*X[i]+Y[i]*Y[i]));
		if(p[i].first>PI) p[i].second-=2*PI,p[i].first-=2*PI;
	}
	sort(p+1,p+n+1);
	for(int i=n+1;i<=n*2;++i) p[i]=p[i-n],p[i].first+=2*PI,p[i].second+=2*PI;
	for(int i=0;i<20;++i) nxt[n*2+1][i]=n*2+1;
	for(int i=1,j=1;i<=n*2;nxt[i++][0]=j) for(;j<=n*2&&p[j].second<p[i].first+eps;++j);
	for(int i=n*2;i;--i) for(int j=1;j<20;++j) nxt[i][j]=nxt[nxt[i][j-1]][j-1];
	for(int i=1,j,k;i<=n;++i){
		for(j=i,k=19;k+1;--k) if((m>>k)&1) j=nxt[j][k];
		if(j>=i+n) return true;
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld%lld",&X[i],&Y[i]),ans=min(ans,(double)sqrt(X[i]*X[i]+Y[i]*Y[i]));
	for(double l=0,r=ans,md;r-l>eps;ans=l) if(chk(md=(l+r)/2)) l=md;else r=md;
	printf("%.9Lf",ans);
	return 0;
}