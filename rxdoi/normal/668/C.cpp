//   Author:Arturia
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
#define rep(x,a,b) for (int x=a;x<=(int)(b);x++)
#define drp(x,a,b) for (int x=a;x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];~x;x=nx[x])
#define ll long long
#define inf (1<<29)
#define PII pair<int,int>
#define PDD pair<double,double>
#define mk(a,b) make_pair(a,b)
#define fs first
#define sc second
#define pb push_back
#define VI vector<int>
#define VS vector<string>
using namespace std;
inline ll rd(){
	ll x=0;int ch=getchar(),f=1;
	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
	if (ch=='-'){f=-1;ch=getchar();}
	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
inline void rt(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>=10) rt(x/10),putchar(x%10+'0');
		else putchar(x+'0');
}
const int maxn=100005;
int n;
double mx[maxn],mn[maxn],a[maxn],b[maxn];
int main(){
	n=rd();
	rep(i,1,n) scanf("%lf",&mx[i]);
	rep(i,1,n) scanf("%lf",&mn[i]);
	rep(i,2,n) mx[i]+=mx[i-1];
	drp(i,n-1,1) mn[i]+=mn[i+1];
	rep(i,1,n-1){
		double x=mx[i],y=-(mn[i+1]-x-1);
		double s1=sqrt(max(1e-10,y*y-4*x));
		a[i]=(y+s1)/2,b[i]=(y-s1)/2;
	}
	a[n]=b[n]=1;
	rep(i,1,n) printf("%.10lf ",a[i]-a[i-1]);puts("");
	rep(i,1,n) printf("%.10lf ",b[i]-b[i-1]);puts("");
}