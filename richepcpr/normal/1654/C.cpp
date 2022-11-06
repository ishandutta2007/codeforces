#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
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
aN a,q1,q2;
void calc(){
    cll n=readll();
    ll w=0;
    rep(i,1,n)w+=a[i]=readll();
    std::sort(a+1,a+n+1);
    ll h1=1,h2=1,t1=1,t2=0,now=n;q1[1]=w;
    while(h1<=t1||h2<=t2){
        cll x=h2>t2||(h1<=t1&&q1[h1]>q2[h2])?q1[h1++]:q2[h2++];
        if(x<a[now]){myputs("NO");return;}
        if(x==a[now]){now--;continue;}
        q1[++t1]=x/2,q2[++t2]=(x+1)/2;
    }
    myputs("YES");
}
int main(){
    IO();
    //gc=getchar; 
    cll T=readll();
    rep(i,1,T)calc();
    return 0;
}
/*aN a,q;
std::map<ll,ll>ma;
void calc(){
    cll n=readll();
    ll w=0;
    ma.clear();
    rep(i,1,n)w+=a[i]=readll(),ma[a[i]]++;
    ll t=1;q[1]=w;
    rep(h,1,t){
        cll x=q[i];
        if(ma[x])ma[x]--;
        if(x==1)
    }
    per(i,n,1){
        while(a[i]<l)l/=2,r=(r+1)/2;
        if(a[i]>r){myputs("NO");return;}
    }
    myputs("YES");
}*/