#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,r;
PII p[3010];
bool xz[3010];
int ans[3010][3010];
double L[3010],R[3010];
const double pi=acosl(-1.0);
double dis(PII x,PII y){
	return sqrtl(powl(x.fi-y.fi,2)+powl(x.se-y.se,2));
}
int main(){
	n=read(),r=read();
	for(int i=1;i<=n;++i) p[i].fi=read(),p[i].se=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j||dis(p[i],p[j])<=r) continue ;
			double t=asinl(r/dis(p[i],p[j]));
			double md=atan2l(p[j].se-p[i].se,p[j].fi-p[i].fi);
			// printf("i:%d,j:%d,%Lf %Lf\n",i,j,t,md);
			if(!xz[i]){
				xz[i]=1;L[i]=md-t,R[i]=md+t;
				// if(L[i]<0) L[i]+=2*pi,R[i]+=2*pi;else if(L[i]>2*pi) L[i]-=2*pi,R[i]-=2*pi;
			}
			else{
				double l=md-t,r=md+t;
				auto canadd=[&](int i,double l,double r){
					return l<=R[i]&&r>=L[i];
				};
				auto add=[&](int i,double l,double r){
					L[i]=max(L[i],l),R[i]=min(R[i],r);
					return ;
				};
				if(canadd(i,l,r)){
					add(i,l,r);
				}
				else if(canadd(i,l+2*pi,r+2*pi)){
					add(i,l+2*pi,r+2*pi);
				}
				else add(i,l-2*pi,r-2*pi);
				// if(l<0) l+=2*pi,r+=2*pi;else if(l>2*pi) l-=2*pi,r-=2*pi;
				// L[i]=max(L[i],l),R[i]=min(R[i],r);
			}
		}
		for(int j=1;j<=n;++j){
			if(i==j) continue ;
			double t=atan2l(p[j].se-p[i].se,p[j].fi-p[i].fi);
			if(!xz[i]||(t>=L[i]&&t<=R[i])||(t+2*pi>=L[i]&&t+2*pi<=R[i])||(t-2*pi>=L[i]&&t-2*pi<=R[i])) ++ans[i][j];
		}
	}
	int Ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j) Ans+=(ans[i][j]&&ans[j][i]);
	}
	printf("%d\n",Ans);
}