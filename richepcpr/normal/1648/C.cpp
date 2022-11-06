#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=998244353,iz=1<<21,oz=1<<22;
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
void writell(cll u,int c=32){
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
aN a;
aN inv;
struct bit{
    aN f;
    ll n;
    void set(ll n_){
        n=n_;
    }
    void update(ll u,cll c){
        for(;u<=n;u+=u&-u)f[u]+=c;
    }
    ll query(ll u)const{
        ll res=0;
        for(;u;u&=~-u)res+=f[u];
        return res;
    }
}dt;
void calc(){
    inv[1]=1;
    rep(i,2,2e5)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    cll n=readll(),m=readll();
    dt.set(2e5);
    ll now=1,x;
    rep(i,1,n)a[x=readll()]++,now=now*inv[a[x]]%mod,dt.update(x,1);
    ll sum=0,mul=1;
    rep(i,1,n)mul=mul*i%mod;
    rep(i,1,m){
        if(i==n+1){
            sum++;
            break;
        }
        cll x=readll();
        mul=mul*inv[n-i+1]%mod;
        //printf("%lld %lld %lld\n",dt.query(x-1),mul,now);
        sum=(sum+dt.query(x-1)*mul%mod*now)%mod;
        dt.update(x,-1);
        now=now*a[x]%mod;
        if(!a[x]--)break;
    }
    writell(sum%mod);
}
int main(){
    IO();
    //gc=getchar; 
    cll T=1;
    rep(i,1,T)calc();
    return 0;
}
/*
4
3 5
1 2 5
4 10
1 3 3 7
1 2
2
1 1
1
*/