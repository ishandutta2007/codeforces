#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;++i)
#define ref(i,l,r) rfor(ll i=l;i<r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define dprintf(x...)fprintf(stderr,x)
#define _cl_lj(a,b) a##b
#define cl_lj(a,b) _cl_lj(a,b)
#define calc_in_func_df(calcer_t,calcer,code...) struct calcer_t{calcer_t(){code}};static calcer_t calcer
#define calc_in_func(code...) calc_in_func_df(cl_lj(calcer_t,__LINE__),cl_lj(calcer,__LINE__),code)
typedef long long ll;typedef long double ld;
const ll inf=0x3f3f3f3f3f3f3f3f;
using std::max;
using std::min;
inline ll readll(void){
	ll x=0,w=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
	for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
	return x*w;
}
inline void writell(ll x,int c='\0'){
	static ll s[112];ll*n=s;
	while(x||n==s)*++n=x%10,x/=10;
	while(n!=s)putchar(*n--^48);
	if(c)putchar(c);
}
inline ll iabs(ll x){
	return max(x,-x);
}
inline int readchar(void){
	int ch=getchar();
	for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());
	return ch;
}
char s[114514];
int main(void){
//    IO(A);
    ll T=readll();
    while(T --> 0){
        ll n=readll(),k=readll();
        scanf("%s",s+1);
        ll now=1;while(s[now]==s[n-now+1]&&now<=(n-1)/2)now++;
//        if(now>(n-1)/2)now=(n-1)/2;
//        printf("%lld\n",now);
        puts(now>k?"YES":"NO");
    }
    return 0;
}