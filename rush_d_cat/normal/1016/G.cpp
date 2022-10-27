#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200000+10;
int n; 
LL x, y, a[N], val[N];
LL dp[1<<20];
int tot = 0;
struct Prime {
    LL p, l, r;
    void prt(){
        printf("val=%lld %lld %lld\n", p,l,r);
    }
} prime[N];
LL gcd(LL x, LL y) {
    return y==0?x:gcd(y,x%y);
}
void init() {
    if (y%x) {
        printf("0\n"); exit(0);
    }
    memset(val,-1,sizeof(val));
    for(LL i=2;i*i*i<=y;i++) {
        int c1=0,c2=0;
        if(x%i==0) {
            while(x%i==0) x/=i, c1++;
        }
        if(y%i==0) {
            while(y%i==0) y/=i, c2++;
        }
        if (c1 || c2) prime[++tot] = (Prime){i,c1,c2};
    }
    /*
    for(LL i=2;i*i*i<=y;i++) {
        int c=0;
        if(y%i==0) {
            while(y%i==0) y/=i, c++;
        }
        if(c) prime[++tot] = (Prime){i,0,c};
    }
    */
    //printf("%lld %lld\n", x,y);

    LL p = (LL)(sqrt(y)+1e-8);
    
    if (p*p == y) { // 
        if (x%(p*p) == 0) { 
            prime[++tot] = (Prime){p,2,2};
        } else if(x%p==0){
            prime[++tot] = (Prime){p,1,2};
        } else {
            prime[++tot] = (Prime){p,0,2};
        }
    } else if (x != 1) { // p p, p pq
        prime[++tot] = (Prime){x,1,1}; 
        if (x != y) prime[++tot] = (Prime){y/x,0,1};
    } else {
        LL q = 1;
        for(int i=1;i<=n;i++) {
            if(gcd(a[i], y) != 1 && gcd(a[i], y) != y) {
                q = gcd(a[i], y);
            }
        }
        if (q != 1) {
            prime[++tot] = (Prime){q,0,1};
            prime[++tot] = (Prime){y/q,0,1};
        } else {
            prime[++tot] = (Prime){y,0,1};
        }
    }
    //for(int i=1;i<=tot;i++) prime[i].prt();
}
int main() {
    scanf("%d %lld %lld", &n, &x, &y); 
    LL cx=x,cy=y;
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        //a[i]=rand();
    }
    init();
    x=cx,y=cy;
    for(int i=1;i<=n;i++) {
        LL mask1 = 0, mask2 = 0;
        LL temp = a[i];
        for(int j=1;j<=tot;j++) {
            if (prime[j].p == 1) continue;
            LL cnt=0;
            while(temp % prime[j].p == 0) temp /= prime[j].p, cnt ++;
            if (prime[j].l == prime[j].r) mask1 |= 1<<(j-1), mask2 |= 1<<(j-1);
            if (cnt == prime[j].l) mask1 |= 1<<(j-1); 
            if (cnt == prime[j].r) mask2 |= 1<<(j-1);
        }
        if (a[i]%x==0) val[i] = mask1; 
        if (y%a[i]==0) dp[mask2] ++; 
    }   
    for(int i=0;i<tot;i++) {
        for(int mask=0;mask<(1<<tot);mask++) {
            if( ((mask>>i)&1) == 0)
                dp[mask] += dp[mask|(1<<i)];
        }
    }
    //printf("! %lld\n", dp[1]);
    LL ans = 0;
    for(int i=1;i<=n;i++) {
        if(a[i]%x==0) ans = ans + dp[((1<<tot)-1) ^ val[i]];
    }
    cout << ans << endl;
}