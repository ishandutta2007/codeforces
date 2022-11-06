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
const ll N=3e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
struct hash{
    static const ll m=9260817;
    ll k[m],v[m],s[m],t;
    mutable ll l;
    ll g(ll&b)const{
        if(!b)b=mod+114514;
        if(k[l]==b)return l;
        ll n=(b%m+m)%m,x=0;
        while(k[n]&&k[n]!=b)n=(n+2*x+++1)%m;
        return l=n;
    }
    int count(ll b)const{
        return!!k[g(b)];
    }
    ll operator[](ll b)const{
        ll n=g(b);
        return k[n]?v[n]:0;
    }
    ll&operator[](ll b){
        ll n=g(b);
        return!k[n]?k[s[++t]=n]=b,v[n]=0:v[n];
    }
    void clear(){
        while(t)k[s[t--]]=0;
    }
}g;
ll cntt=0;
ll get_hs(ll x){
    return g.count(x)?g[x]:g[x]=++cntt;
}
std::vector<ll>v[N];
aN b,c,st0,st1,nxt,cnt;
void calc(){
    ll n=readll(),t0=0,t1=0,sum=0;
    g.clear(),cntt=0;
    rep(i,1,n)b[i]=readll()-b[i-1],v[i].clear();
    v[get_hs(0)].push_back(0),cnt[0]=1;
    rep(i,1,n)c[i]=i&1?-b[i]:b[i],v[get_hs(c[i])].push_back((ll)i),cnt[i]=v[get_hs(c[i])].size();
    //rep(i,1,n)printf("%lld %lld %lld %lld\n",c[i],nxt[i],cnt[i],get_hs(c[i]));
    st0[0]=st1[0]=n+1;
    per(i,n,1){
        if(~i&1){
            while(t0&&c[i]<c[st0[t0]])t0--;
            st0[++t0]=i;
        }else{
            while(t1&&c[i]>c[st1[t1]])t1--;
            st1[++t1]=i;
        }
        ll p=n+1;
        ll l=0,r=t0;
        while(l<=r){
            const ll mid=(l+r)>>1;
            if(c[st0[mid]]<c[i-1]||mid==0)l=mid+1;
            else r=mid-1;
        }
        p=std::min(p,st0[l-1]);
        l=0,r=t1;
        while(l<=r){
            const ll mid=(l+r)>>1;
            if(c[st1[mid]]>c[i-1]||mid==0)l=mid+1;
            else r=mid-1;
        }
        p=std::min(p,st1[l-1]);
        #define all(x) (x).begin(),(x).end()
        //printf("%lld %lld %lld %lld\n",i,p,*--std::lower_bound(all(v[get_hs(c[i-1])]),p),
        //cnt[*--std::lower_bound(all(v[get_hs(c[i-1])]),p)]-cnt[i-1]);
        sum+=cnt[*--std::lower_bound(all(v[get_hs(c[i-1])]),p)]-cnt[i-1];
    }
    writell(sum,10);
    /*per(i,n,0)g[c[i]]=i;
    st[0]=-1;
    rep(i,0,n){
        while(t&&c[i]>=c[st[t]])t--;
        const ll p=st[t];
        printf("%lld %lld\n",i,p);
        ll&now=g[c[i]];
        while(now<p)now=nxt[now];
        printf("%lld\n",now);
        if(~i&1)sum+=cnt[i]-cnt[now];
        printf("sum=%lld\n",sum);
        st[++t]=i;
    }
    t=0;
    per(i,n,0)g[c[i]]=i;
    rep(i,0,n){
        while(t&&c[i]<=c[st[t]])t--;
        const ll p=st[t];
        ll&now=g[c[i]];
        while(now<p)now=nxt[now];
        if(i&1)sum+=cnt[i]-cnt[now];
        st[++t]=i;
    }*/
}
int main(){
    IO();
    ll T=readll();
    while(T--)calc(); 
    return 0;
}