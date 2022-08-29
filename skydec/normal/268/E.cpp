#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 51000
db l[MAXN],ps[MAXN];
int id[MAXN];
int n;
inline bool cmp(const int &ax,const int &bx){
	db a,p,s,b;
	a=l[ax];p=ps[ax];
	b=l[bx];s=ps[bx];
	return -s*a*p+a*p>-p*b*s+b*s;
}
int work(){
	db cost=0;db k=0;
	rep(x,1,n){
		int i=id[x];
		cost+=(l[i]+k)*(1-ps[i])+l[i]*ps[i];
		k+=l[i]*ps[i];
	}
	printf("%.10lf\n",cost);
}
int main(){
	scanf("%d",&n);rep(i,1,n){scanf("%lf%lf",&l[i],&ps[i]);ps[i]/=100.;id[i]=i;}
	sort(id+1,id+1+n,cmp);
	work();
	return 0;
}