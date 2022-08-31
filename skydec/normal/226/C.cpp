#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(LL i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
int m;
inline void A(int &x,int y){x+=y;if(x>=m)x-=m;}
inline int M(int x,int y){x=x*1ll*y%m;return x;}
struct ww{
	int a[2][2];
	inline ww operator *(const ww &b)const{
		ww c;memset(c.a,0,sizeof c.a);
		rep(k,0,1)rep(i,0,1)rep(j,0,1)A(c.a[i][j],M(a[i][k],b.a[k][j]));
		return c;
	}
};
int getF(LL x){
	if(x==1)return 1;
	ww a,c;x-=2ll;memset(a.a,0,sizeof a.a);memset(c.a,0,sizeof c.a);
	c.a[0][0]=c.a[1][1]=1;
	a.a[0][1]=a.a[1][1]=a.a[1][0]=1;
	for(;x;x>>=1,a=a*a)if(x&1)c=c*a;
	int res=c.a[1][1];
	A(res,c.a[0][1]);
	return res;
}
LL l,r,k;
bool check(LL x){
	return r/x - (l+x-1)/x+1>=k;
}
int main(){
	scanf("%d",&m);
	scanf("%I64d%I64d%I64d",&l,&r,&k);
	LL ress=1;
	LL st=max((LL)sqrt(r),1ll);
	rep(i,1,st)ress=max(ress,i*check(i));
	rep(i,1,r/st)ress=max(ress,(r/i)*check(r/i));
	printf("%d\n",getF(ress)%m);
	return 0;
}