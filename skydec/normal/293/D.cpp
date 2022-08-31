#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef long double db;
typedef set<int>::iterator it;
const int N=2010000;
int x[110000],y[110000];int n;
db sumx2,sumx,sum;
db sumy2,sumy;
db l[N+5],r[N+5];
const db dw=1.;
inline void cover(int x1,int y1,int x2,int y2){
	if(x1>x2){
		swap(x1,x2);
		swap(y1,y2);
	}
	if(x1==x2){
		l[x1]=min(l[x1],dw*min(y2,y1));
		r[x1]=max(r[x1],dw*max(y2,y1));
	}
	else{
		rep(k,x1,x2){
			db jiao=(y2-y1)*((k-x1)*dw/(x2-x1))+y1;
			r[k]=max(r[k],jiao);
			l[k]=min(l[k],jiao);
		}
	}
}
inline void Do(){
	rep(i,0,N)l[i]=N,r[i]=0;
	rep(i,1,n)cover(x[i],y[i],x[i+1],y[i+1]);
	rep(i,0,N)if(l[i]<N-2){
		int a1=ceil(l[i]);
		int a2=(int)r[i];
		db ll=a1*1.;
		db rr=a2*1.;
		sum+=rr-ll+1;
		sumx+=(rr-ll+1)*i;
		sumx2+=(rr-ll+1)*1.*i*i;	
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&x[i],&y[i]);
		x[i]+=N/2;
		y[i]+=N/2;
	}
	x[n+1]=x[1];y[n+1]=y[1];
	Do();rep(i,1,n+1)swap(x[i],y[i]);
	sumy2=sumx2;
	sumy=sumx;
	sumx2=sumx=sum=0;
	Do();
	db ans=sum*sumx2-sumx*sumx+sum*sumy2-sumy*sumy;
	ans/=sum;ans/=(sum-1);
	printf("%.10lf\n",(double)ans);
	return 0;
}