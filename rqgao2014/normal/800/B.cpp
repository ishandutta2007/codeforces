#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;

const int N=100005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}

struct line{double a,b,c;}l;
int n,x[N],y[N];

line make(int x1,int y1,int x2,int y2){
	if(x1==x2) return (line){1.0,0.0,-(double)x1};
	if(y1==y2) return (line){0.0,1.0,-(double)y1};
	double a=1,b=(double)(x2-x1)/(double)(y1-y2),c=-x1-b*y1;
	return (line){a,b,c};
}

double get(line a,int x,int y){
	return abs((double)(a.a*x+a.b*y+a.c)/sqrt(sqr(a.a)+sqr(a.b)));
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
		
	double ans=1e10;
	for(int i=0;i<n;i++){
		l=make(x[(i+1)%n],y[(i+1)%n],x[(i+n-1)%n],y[(i+n-1)%n]);
		ans=min(ans,get(l,x[i],y[i]));
//		ans=min(ans,sqrt(sqr((double)x[i]-x[(i+1)%n])+sqr((double)y[i]-y[(i+1)%n])));
	}
	printf("%.9f\n",ans/2.0);
	return 0;
}