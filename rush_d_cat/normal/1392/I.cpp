#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000+10;
const double PI = acos(-1);
struct Complex {
    double x, y;
    Complex(double x=0.0, double y=0.0) : x(x), y(y) {}
    Complex operator + (const Complex &b) const {
        return Complex(x+b.x, y+b.y);
    }
    Complex operator - (const Complex &b) const {
        return Complex(x-b.x, y-b.y);
    }
    Complex operator * (const Complex &b) const{
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
} x1[N], x2[N];
void change(Complex y[], int len) {
    for(int i=1,j=len/2;i<len-1;i++){
        if(i<j) swap(y[i], y[j]);
        int k=len/2;
        while (j>=k) {
            j-=k; k/=2;
        }
        if(j<k) j+=k;
    }
}
void fft(Complex y[], int len, int on){
    change(y, len);
    for(int h=2;h<=len;h<<=1) {
        Complex wn(cos(-on*2*PI/h), sin(-on*2*PI/h));
        for(int j=0;j<len;j+=h){
            Complex w(1,0);
            for(int k=j;k<j+h/2;k++) {
                Complex u=y[k];
                Complex t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if (on==-1) for(int i=0;i<len;i++) y[i].x /= len;
}
void mul(LL *p, int& dp, LL* q, int& dq) {
    int len=1;
    while(len<=dp+dq) len<<=1;
    for(int i=0;i<dp;i++) x1[i]=Complex(p[i],0);
    for(int i=dp;i<len;i++) x1[i]=Complex(0,0);
    for(int i=0;i<dq;i++) x2[i]=Complex(q[i],0);
    for(int i=dq;i<len;i++) x2[i]=Complex(0,0);
    fft(x1,len,1);
    fft(x2,len,1);
    for(int i=0;i<len;i++) {
        x1[i]=x1[i]*x2[i];
    }
    fft(x1,len,-1);
    for(int i=0;i<N;i++){
        //printf("%.4f\n", x1[i].x);
        p[i]=round(x1[i].x);
    }
    dp+=dq;
}

LL n,m;int q;
const int B=100000+10;
int a[N],b[N];
namespace Min{
    LL f[N],g[N];
    LL s1[N], s2[N], s3[N];
    void gen1() {
        memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++) f[a[i]] ++;
        for(int i=1;i<m;i++) g[min(b[i],b[i+1])] ++;
        int dp=B,dq=B;
        mul(f,dp,g,dq); s1[0]=0;
        for(int i=1;i<=2*B+2;i++) s1[i]=s1[i-1]+f[i];
    } 
    void gen2() {
        memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
        for(int i=1;i<n;i++) f[min(a[i],a[i+1])] ++;
        for(int i=1;i<=m;i++) g[b[i]] ++;
        int dp=B,dq=B;
        mul(f,dp,g,dq); s2[0]=0;
        for(int i=1;i<=2*B+2;i++) s2[i]=s2[i-1]+f[i];
    } 
    void gen3() {
        memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
        for(int i=1;i<n;i++) f[min(a[i],a[i+1])] ++;
        for(int i=1;i<m;i++) g[min(b[i],b[i+1])] ++;
        int dp=B,dq=B;
        mul(f,dp,g,dq); s3[0]=0;
        for(int i=1;i<=2*B+2;i++) s3[i]=s3[i-1]+f[i];
    } 
}
namespace Max{
    LL f[N<<1],g[N<<1];
    LL s1[N], s2[N], s3[N], s4[N];
    void gen1() {
        memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++) f[a[i]] ++;
        for(int i=1;i<m;i++) g[max(b[i],b[i+1])] ++;
        int dp=B,dq=B;
        mul(f,dp,g,dq);
        s1[0]=0;
        for(int i=1;i<=2*B+2;i++) s1[i]=s1[i-1]+f[i];
    } 
    void gen2() {
        memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
        for(int i=1;i<n;i++) f[max(a[i],a[i+1])] ++;
        for(int i=1;i<=m;i++) g[b[i]] ++;
        int dp=B,dq=B;
        mul(f,dp,g,dq);
        s2[0]=0;
        for(int i=1;i<=2*B+2;i++) s2[i]=s2[i-1]+f[i];
    } 
    void gen3() {
        memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
        for(int i=1;i<n;i++) f[max(a[i],a[i+1])] ++;
        for(int i=1;i<m;i++) g[max(b[i],b[i+1])] ++;
        int dp=B,dq=B;
    /*
    printf("f\n");
        for(int i=0;i<7;i++) printf("%d ", f[i]); printf("\n");
    printf("g\n");
        for(int i=0;i<7;i++) printf("%d ", g[i]); printf("\n");
    */
        mul(f,dp,g,dq);
    //printf("m\n");
        //for(int i=0;i<7;i++) printf("%d ", f[i]); printf("\n");  
        s3[0]=0;
        for(int i=1;i<=2*B+2;i++) s3[i]=s3[i-1]+f[i];
    } 
    void gen4() {
        memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++) f[a[i]] ++;
        for(int i=1;i<=m;i++) g[b[i]] ++;
        int dp=100001,dq=100001;
        mul(f,dp,g,dq);
        s4[0]=0;
        for(int i=1;i<=200000+2;i++) s4[i]=s4[i-1]+f[i];
    }
}

int main() {
    scanf("%lld%lld%d", &n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    Min::gen1(); Min::gen2(); Min::gen3();
    Max::gen1(); Max::gen2(); Max::gen3(); Max::gen4();
    //printf("# %d\n", Max::s3[4]);
    while(q--) {
        int x; scanf("%d",&x);
        LL ans1 = (1LL*n*(m-1) - Min::s1[x-1]) + (1LL*(n-1)*m - Min::s2[x-1]) - (1LL*n*m - Max::s4[x-1]) - (1LL*(n-1)*(m-1) - Min::s3[x-1]);
        LL ans2 = Max::s1[x-1] + Max::s2[x-1] - Max::s4[x-1] - Max::s3[x-1];
        printf("%lld\n", ans2-ans1);
    }
}