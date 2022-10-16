#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
int n,m;
ll a[Maxn+5],b[Maxn+5],l,r;
void init(){
    int it=1;
    for(int i=2;i<=n;i++){
        if(a[i+1]-a[i]>a[it+1]-a[it]){
            it=i;
        }
    }
    r=a[it+1]-a[it]-1;
    for(int i=1;i<=n;i++){
        b[i]=a[i+it];
    }
    ll tmp=b[1];
    for(int i=1;i<=n;i++){
        b[i]-=tmp;
    }
}
ll f[Maxn+5];
bool check(ll x){
    f[1]=0;
    for(int i=2;i<=n;i++){
        f[i]=f[i-1];
        if(f[i-1]>=b[i]-1){
            f[i]=std::max(f[i],b[i]+x);
        }
        if(f[i-1]>=b[i]-x-1){
            f[i]=std::max(f[i],b[i]);
        }
        if(i>2&&f[i-2]>=b[i]-x-1){
            f[i]=std::max(f[i],b[i-1]+x);
        }
    }
    if(f[n]>=m-x-1){
        return 1;
    }
    f[2]=std::max(b[2],x);
    for(int i=3;i<=n;i++){
        f[i]=f[i-1];
        if(f[i-1]>=b[i]-1){
            f[i]=std::max(f[i],b[i]+x);
        }
        if(f[i-1]>=b[i]-x-1){
            f[i]=std::max(f[i],b[i]);
        }
        if(f[i-2]>=b[i]-x-1){
            f[i]=std::max(f[i],b[i-1]+x);
        }
    }
    if(f[n]>=std::min(1ll*m-1,m+b[2]-x-1)){
        return 1;
    }
    return 0;
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i+n]=a[i]+m;
    }
    if(n==1){
        printf("%d\n",m-1);
        return 0;
    }
    std::sort(a+1,a+1+(n<<1));
    init();
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    printf("%lld\n",l);
    return 0;
}