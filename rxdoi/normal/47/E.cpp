#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<string>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<bitset>
#include<vector>
#define rep(x,a,b) for (int x=a;x<=(int)b;x++)
#define drp(x,a,b) for (int x=a;x>=(int)b;x--)
#define cross(x,a) for (int x=hd[a];~x;x=nx[x])
#define ll long long
#define inf (1<<29)
#define PII pair<int,int>
#define PDD pair<double,double>
#define mk(a,b) make_pair(a,b)
#define fs first
#define sc second
#define pb push_back
using namespace std;
inline ll rd(){
	ll x=0;int ch=getchar(),f=1;
	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
	if (ch=='-'){f=-1;ch=getchar();}
	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
#define eps 1e-10
inline void rt(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>=10) rt(x/10),putchar(x%10+'0');
		else putchar(x+'0');
}
const int maxn=10005,maxm=100005;
struct query{
	double ang;
	int id;
	query(double ANG=0,int ID=0){ang=ANG,id=ID;}
	bool operator <(const query&x)const{return ang<x.ang;}
}a[maxn];
struct wall{
	double x,y;
	bool operator <(const wall&w)const{return abs(x-w.x)<eps?y<w.y:x<w.x;}
}b[maxm];
double ans[maxn][2];
double sqr(double a){return a*a;}
int m,n,v;
int main(){
	n=rd(),v=rd();
	rep(i,1,n){
		double x;
		scanf("%lf",&x);a[i]=query(x,i);
	}
	sort(a+1,a+n+1);
	m=rd();
	rep(i,1,m) scanf("%lf%lf",&b[i].x,&b[i].y);
	sort(b+1,b+m+1);
	int j=1;
	rep(i,1,n){
		double tn=tan(a[i].ang),cs=cos(a[i].ang),sn=sin(a[i].ang);
		bool zq=0;
		while (j<=m){
			double t=b[j].x/(v*cs);
			if (b[j].y+eps>v*sn*t-4.9*sqr(t)){
				if (v*sn*t-4.9*sqr(t)+eps<0) break;
				ans[a[i].id][0]=b[j].x,ans[a[i].id][1]=v*sn*t-4.9*sqr(t);
				zq=1;break;
			}
			j++;
		}
		if (!zq){
			double t=v*sn/4.9;
			ans[a[i].id][0]=v*cs*t,ans[a[i].id][1]=0;
		}
	/*	while (j<=m&&b[j].y-(b[j].x*tn-4.9*sqr(b[j].x/(cs*V)))<eps) j++;
		double xx=V*sn*V*cs/4.9;
		if (j<=m&&b[i].x-xx<eps){
			ans[a[i].id][0]=b[j].x;
			ans[a[i].id][1]=b[j].x*tn-4.9*sqr(b[j].x/(cs*V));
		}
		else{
			ans[a[i].id][0]=xx;
			ans[a[i].id][1]=0;
		}*/
	}
	rep(i,1,n) printf("%.9lf %.9lf\n",ans[i][0],ans[i][1]);
}