#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define M 100100
bool flag[M];
int n, m, p;
int qn, deg[100];
ll a[M], b[M], P;
ll q[100];
int bit[1<<22], gg[1<<22];;

void init();

ll gcd(ll a, ll b){return a?gcd(b%a, a):b;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
ll pow(ll a, ll k){
    ll s=1, b=a;
    while(k){
        if(k&1)s=s*b%P;
        b=b*b%P;
        k/=2;
    }
    return s;
}

int main(){
    ///freopen("4.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &p);
    P=1ll*p;
    init();
    int i, j, k;
    ll tmp;
    for(i=0; i<n; i++)scanf("%I64d", a+i);
    ll g=ll(p-1);
    for(j=0; j<m; j++)scanf("%I64d", &tmp),g = gcd(g, tmp);
    //printf("g = %I64d\n", g);

    for(i=0; i<n; i++){
        a[i]=pow(a[i], g);
        b[i]=P-1;
        for(j=0; j<qn; j++){
            while(b[i]%q[j]==0 and pow(a[i], (b[i]/q[j]))==1ll)b[i]/=q[j];
        }
        b[i]=(P-1)/b[i];
        //printf("b[%d] = %I64d\n", i, b[i]);
    }

    sort(b, b+n);
    n=unique(b, b+n)-b;
    for(i=n-1; i>=0; i--){
        for(j=i-1; j>=0; j--){
            if(b[i]%b[j]==0){flag[i]=1; break;}
        }
    }
    int nn=0;
    for(i=0; i<n; i++)if(!flag[i])a[nn++]=b[i];
    n=nn;
    //printf("n=%d\n", n);
    //for(i=0; i<n; i++)printf("%d ", a[i]);puts("");

    int w=1<<n;
    ll ans=0;
    gg[0]=1;
    //printf("w = %I64d\n", w);
    for(i=1; i<w; i++){
        bit[i]=bit[i/2]+(i%2);
        for(j=0; j<n; j++)if(i&(1<<j))break;
        gg[i]=lcm(gg[i-(1<<j)], a[j]);
        if(bit[i]%2==1)ans += (P-1)/gg[i];
        else ans -= (P-1)/gg[i];
    }
    printf("%I64d\n", ans);
    return 0;
}

void init(){
    int i, j, k;
    int pp=P-1;
    for (i=2; i*i<=pp; i++)if(pp%i==0){
        q[qn]=i;
        while(pp%i==0)pp/=i, deg[qn]++;
        qn++;
    }
    if(pp>1)q[qn]=pp, deg[qn++]=1;
    //printf("qn = %d\n", qn);
}