#include<cstdio>
#include<climits>
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
typedef long long ll;
ll n,m,sum=0;
ll a[100005],b[100005];
inline ll read() {
    register ll x=0,f=1;register char s=getchar();
    while(s>'9'||s<'0') {if(s=='-') f=-1;s=getchar();}
    while(s>='0'&&s<='9') {x=x*10+s-'0';s=getchar();}
    return x*f;
}
//-3*y^2+3*y+x-1=-3(y-(1/2))^2+...
inline ll f(ll x,ll y) {return x==y? LLONG_MAX:x-3*y*(y-1)-1;}//x=1/2
inline ll calc(ll x,ll lim) {//f(a[x],b[x])<=lim
    ll l=1,r=a[x],res=a[x];
    while(l<=r) {
        int mid=l+r>>1;
        if(f(a[x],mid)<=lim) {r=mid-1;res=mid;}
        else {l=mid+1;} 
    }
    return res;
}
inline bool check(ll x) {
    sum=0;
    for(register int i=1;i<=n;++i) {
        b[i]=calc(i,x);
        sum+=b[i];
    }
    return sum<m;
}
int main() {
    n=read();m=read();
    ll l=0,r=0;
    for(register int i=1;i<=n;++i) {
        a[i]=read();
        l=min(l,f(a[i],a[i]-1));
        r=max(r,f(a[i],0));
    }
    while(l+1<r) {
        ll mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid;
    }
    if(check(l)) r=l;
    check(r);
    m-=sum;
    for(register int i=1;i<=n;++i) if(m>0&&b[i]<a[i]&&f(a[i],b[i])==r) ++b[i],--m; 
    for(register int i=1;i<=n;++i) printf("%lld ",b[i]);
    return 0;
}