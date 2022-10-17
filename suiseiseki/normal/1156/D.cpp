#include <bits/stdc++.h>
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define PER(i,a,n) for(int i=n;i>=a;--i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {
	return b?gcd(b,a%b):a;
}
ll qpow(ll a,ll n) {
	ll r=1%P;
	for (a%=P; n; a=a*a%P,n>>=1)if(n&1)r=r*a%P;
	return r;
}
ll inv(ll x) {
	return x<=1?1:inv(P%x)*(P-P/x)%P;
}
inline int rd() {
	int x=0;
	char p=getchar();
	while(p<'0'||p>'9')p=getchar();
	while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();
	return x;
}
const int N = 1e6+10;
int n, sz1[N], sz2[N], fa1[N], fa2[N];
int f1(int x){
	return fa1[x]?fa1[x]=f1(fa1[x]):x;
}
int f2(int x){
	return fa2[x]?fa2[x]=f2(fa2[x]):x;
}
void add1(int x,int y){
	if((x=f1(x))!=(y=f1(y))){
		fa1[x]=y,sz1[y]+=sz1[x];
	} 
}
void add2(int x, int y) {
	if((x=f2(x))!=(y=f2(y))){
		fa2[x]=y,sz2[y]+=sz2[x];
	}
}
int main(){
	scanf("%d",&n);
	REP(i,1,n){
		sz1[i]=sz2[i]=1;
	}
	REP(i,2,n){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		w?add2(u,v):add1(u,v);
	}
	ll ans=0;
	REP(i,1,n){
		ans+=(ll)sz1[f1(i)]*sz2[f2(i)]-1;
	}
	printf("%lld\n",ans);
	return 0;
}