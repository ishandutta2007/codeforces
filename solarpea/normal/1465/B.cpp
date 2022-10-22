#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T>
void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
ll n;
void solve(){
	scanf("%lld",&n);
	for(ll i=n;i<=n+2520;i++){
		ll tmp=i;vector<int> vv;
		while(tmp) vv.pb(tmp%10),tmp/=10;
		bool flg=1;ffe(it,vv){if((*it)>0) flg&=(i%(*it)==0);}
		if(flg){printf("%lld\n",i);break;}
	}
}
signed main(){
	int qu;scanf("%d",&qu);while(qu--) solve();
	return 0;
}