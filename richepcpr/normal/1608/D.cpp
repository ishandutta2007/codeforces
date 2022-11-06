#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef unsigned long long ull;
const ll N=1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1==o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126){
    if(l>r)std::swap(l,r);
    int c=gc();
    for(;c<l||c>r;c=gc());
    return c;
}
ll readll(){
    ll x=0,w=1;
    int c=gc();
    for(;c<48||c>57;c=gc())c-45||(w=-w);
    for(;c>47&&c<58;c=gc())x=x*10+c-48;
    return x*w;
}
void writell(ll u,int c=32){
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10^48;
    for(t||pc(48);t;)pc(wt[t--]);
    c&&pc(c);
}
int mygets(char*s,int c=0){
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
static inline int zh(int c){
    switch(c){
        case'W':return 0;
        case'B':return 1;
        case'?':return 2;
    }
    __builtin_unreachable();
}
static inline int getread(){
    const ll a=zh(readchar()),b=zh(readchar());
    return a*3+b;
}
enum{ww,wb,ws,bw,bb,bs,sw,sb,ss};
aN t,jc,njc;
ll inv(ll a,ll b=mod){
    ll x=1,y=0;
    const ll m=b;
    while(b){
        const ll t=a/b;
        std::swap(a-=t*b,b),
        std::swap(x-=t*y,y);
    }
    return(x+m)%m;
}
ll pow(ll a,ll b,ll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}
ll C(ll n,ll m){
    return n<0||n>m?0:jc[m]*njc[n]%mod*njc[m-n]%mod;
}
int main(){
    IO();
    const ll n=readll(),m=n*2;
    rep(i,jc[0]=1,m)jc[i]=jc[i-1]*i%mod;
    njc[m]=inv(jc[m]);
    per(i,m,1)njc[i-1]=njc[i]*i%mod;
    rep(i,1,n)t[getread()]++;
    const ll del=t[bb]+t[bs]+t[sb]+t[ss]-t[ww],gs=t[ws]+t[sw]+t[bs]+t[sb]+t[ss]*2;
    const ll only_BW=t[bw]+t[bs]+t[sw]+t[ss]==n,only_WB=t[wb]+t[sb]+t[ws]+t[ss]==n;
    const ll no_WWBB=!t[ww]&&!t[bb]?pow(2,t[ss]):0;
    writell((C(del,gs)-no_WWBB+only_BW+only_WB+mod)%mod);
    return 0;
}