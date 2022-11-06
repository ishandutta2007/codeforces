#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=6e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os;
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
cll IO_res=IO(),T=readll();
bool p1;
aN x,xx,pp,st[22],ans;//0[22],st1[22],st2[22];
struct node{
    ll x,z;
    operator ll()const{
        return x;
    }
}p[N];
struct pt{
    ll y,z;
    void merge(const node&m){
        z+=m.z;
    }
    void calc(cll s){
        y+=s*z;
    }
};
ll query(aN(&st)[22],cll l,cll r){
    cll lg=31^__builtin_clz(r-l+1);
    return std::max(st[lg][l],st[lg][r-(1<<lg)+1]);
}
bool p2;
void calc(){
    cll n=readll(),m=readll();
    ll t=0;
    rep(i,1,n){
        cll x=xx[i]=readll(),p=pp[i]=readll();
        ::p[++t]=(node){x-p,1},
        ::p[++t]=(node){x,-2},
        ::p[++t]=(node){x+p,1};
    }
    std::sort(p+1,p+t+1);
    rep(i,1,n)xx[i]-=p[1].x;
    per(i,t,1)p[i].x-=p[1].x;
    rep(i,1,t)x[i]=p[i].x;
    pt s0={0,0};
    rep(i,1,t){
        st[0][i]=s0.y,
        //st1[0][i]=s0.y-p[i].x,
        //st2[0][i]=s0.y+p[i].x,
        //printf("= %lld %lld %lld %lld\n",st0[0][i],st1[0][i],st2[0][i],p[i].x);
        s0.merge(p[i]);
        if(i!=t)s0.calc(p[i+1].x-p[i].x);
    }
    rep(i,0,21)rep(j,1,t-(2<<i)+1)st[i+1][j]=std::max(st[i][j],st[i][j+(1<<i)]);
    rep(i,1,n){
        cll a=std::lower_bound(x+1,x+t+1,xx[i]-pp[i])-x,
            c=std::lower_bound(x+1,x+t+1,xx[i]+pp[i])-x;
        ans[i]=std::max(query(st,1,a),query(st,c,t));
    }
    rep(i,1,t)st[0][i]-=x[i];
    rep(i,0,21)rep(j,1,t-(2<<i)+1)st[i+1][j]=std::max(st[i][j],st[i][j+(1<<i)]);
    rep(i,1,n){
        cll a=std::lower_bound(x+1,x+t+1,xx[i]-pp[i])-x,
            b=std::lower_bound(x+1,x+t+1,xx[i])-x;
        ans[i]=std::max(ans[i],query(st,a,b)+x[a]);
    }
    rep(i,1,t)st[0][i]+=2*x[i];
    rep(i,0,21)rep(j,1,t-(2<<i)+1)st[i+1][j]=std::max(st[i][j],st[i][j+(1<<i)]);
    rep(i,1,n){
        cll b=std::lower_bound(x+1,x+t+1,xx[i])-x,
            c=std::lower_bound(x+1,x+t+1,xx[i]+pp[i])-x;
        ans[i]=std::max(ans[i],query(st,b,c)-x[c]);
    }
    rep(i,1,n)pc(49-(ans[i]>m));
    pc(10);
}
int main(){
    //fprintf(stderr,"%fMiB\n",(&p2-&p1)/1048576.0); 
    rep(i,1,T)calc();
    return 0;
}