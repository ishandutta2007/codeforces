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
ll p[1145141],q[1145141],l[1145141];
int main(void){
//    IO(C);
    ll n=readll(),t=0;
    rep(i,1,n)p[i]=readll();
    ll lst=-1;
    rep(i,2,n){
        ll x=p[i]>p[i-1];
        x!=lst?q[++t]=1:q[t]++;
        l[t]=lst=x;
    }
    #define max nowmax
    ll max=-1,sum=0;
    rep(i,1,t){
        if(q[i]>max)max=q[i],sum=0;
        if(q[i]==max)sum++;
//        printf("%lld\n",q[i]);
    }
//    if(p[1]==39390)if(sum!=2)return puts(sum>2?"01":"07"),0;
    if(sum!=2)return puts("0"),0;
    else{
        ll b=0;rep(i,1,t-1)if(q[i]==max&&q[i+1]==max&&l[i]==1)b=1;
//        if(p[1]==39390)if(!b)return puts("02"),0;
//        else return puts(max&1?"03":"1"),0;
        if(!b)return puts("0"),0;
        else return puts(max&1?"0":"1"),0;
    }
    return 0;
}
/*
4
1 3 2 1
12
1 2 3 4 5 4 3 2 1 6 7 8
*/