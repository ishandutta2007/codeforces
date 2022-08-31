#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
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
typedef double db;
const int maxn=11000;
const LL inf=(LL)1e12;
LL gcd(LL a,LL b){
	if(!a||!b)return a+b;
	return gcd(b,a%b);
}
LL exgcd(LL a,LL b,LL &x,LL &y){
	if(!b){x=1;y=0;return a;}
	LL d=exgcd(b,a%b,x,y);
	LL tmp=y;y=(x-(a/b)*y);x=tmp;
	return d;
}
LL n,m;int k;LL a[maxn];
int main(){
	scanf("%I64d%I64d%d",&n,&m,&k);
	LL lcm=1;
	rep(i,1,k){
		scanf("%I64d",&a[i]);
		LL d=gcd(lcm,a[i]);
		if(lcm/d>n/a[i]){
			printf("NO");
			return 0;
		}
		lcm=(lcm/d)*a[i];
	}
	m=min(m-k+1,lcm);
	// x=g(mod t)
	LL t=a[1];LL g=0;
	rep(i,2,k){
		LL c=-(i-1)-g;LL x,y;
		LL d=exgcd(t,a[i],x,y);
		if(c%d!=0){
			printf("NO");
			return 0;
		}
		LL kk=c/d;
		LL qp=a[i]/d;
		x=((x*kk)%qp+qp)%qp;
		g=(g+t*x)%lcm;
		t=(t/d)*a[i]%lcm;
	}
	if(g<=0)g+=lcm;
	if(g>m){printf("NO");return 0;}
	rep(i,1,k){
		if(gcd(lcm/a[i],(g+i-1)/a[i])!=1){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}