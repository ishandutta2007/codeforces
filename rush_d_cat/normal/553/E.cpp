#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1000000+10;
const double INF = 1e9+7;
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
} x1[N<<2], x2[N<<2];
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
    if (on==-1)
        for(int i=0;i<len;i++) y[i].x /= len;
}
void mul(double *p, int& dp, double* q, int& dq) {
    //printf("-----------------------------------\n");
    //for(int i=0;i<dp;i++) printf("%.5f ", p[i]); printf("\n");
    //for(int i=0;i<dq;i++) printf("%.5f ", q[i]); printf("\n");
    int len=1;
    while(len<=dp+dq) len<<=1;
    for(int i=0;i<dp;i++) 
        x1[i]=Complex(p[i],0);
    for(int i=dp;i<len;i++)
        x1[i]=Complex(0,0);
    for(int i=0;i<dq;i++)
        x2[i]=Complex(q[i],0);
    for(int i=dq;i<len;i++)
        x2[i]=Complex(0,0);
    fft(x1,len,1);
    fft(x2,len,1);
    for(int i=0;i<len;i++)
        x1[i]=x1[i]*x2[i];
    fft(x1,len,-1);
    for(int i=0;i<dp+dq;i++) {
        p[i]=x1[i].x;
    }
    dp+=dq;
    //for(int i=0;i<dp;i++) printf("%.5f ", p[i]); printf("\n");
    //printf("----------------------------------\n");
}

int n,m,t,x;
int dis[52][52],a[102],b[102],c[102];
double f[102][100000+10],g[102][100000+10],p[102][100000+10],suf[102][100000+10];
double po1[100000+10],po2[100000+10]; int d1=0,d2=0;
void change(int x,int l,int r){
    int mid=(l+r)>>1;
    // f[x][y:l~mid] x p[x][l~r] update f[x][mid+1~r]
    //printf("x=%d,l=%d,r=%d\n", x,l,r);
    d1=(mid-l+1)+1; for(int i=1;i<d1;i++)po1[i]=f[b[x]][i+l-1];
    d2=(r-l+1)+1;   for(int i=1;i<d2;i++)po2[i]=p[x][i];
    mul(po1,d1,po2,d2);
    for(int i=(mid-l+1)+1;i<(r-l+1)+1;i++)g[x][l+i-1]+=po1[i];
}
void solve(int l,int r){
    //printf("solve %d %d\n", l,r);
    if(l==r) {
        if(!l)return;
        for(int i=1;i<=m;i++){
            //printf("g[%d][%d]=%.5f\n", i,l,g[i][l]);
            f[a[i]][l]=min(f[a[i]][l], g[i][l]);
        }
        //printf("res: \n");
        //for(int i=1;i<=n;i++)printf("f[%d][%d]=%.5f\n", i,l,f[i][l]);
        return;
    }
    int mid=(l+r)>>1;
    solve(l,mid);
    for(int i=1;i<=m;i++)change(i,l,r);
    solve(mid+1,r);
    //for(int i=1;i<=n;i++)for(int j=0;j<t;j++)printf("g[%d][%d]=%.5f\n", i,j,g[i][j]);
}
int main(){
    scanf("%d%d%d%d",&n,&m,&t,&x);++t;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=i==j?0:INF;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]); dis[a[i]][b[i]]=c[i];
        for(int j=1;j<t;j++)scanf("%lf",&p[i][j]),p[i][j]/=100000.0;
        for(int j=t-1;j>=0;j--)suf[i][j]=suf[i][j+1]+p[i][j];
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    //for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("dis[%d][%d]=%d\n", i,j,dis[i][j]);
    //for(int i=1;i<=n;i++)for(int j=0;j<t;j++)printf("suf[%d][%d]=%.6f\n", i,j,suf[i][j]);
    for(int i=0;i<=n;i++)for(int j=0;j<=t;j++)f[i][j]=INF;
    for(int i=1;i<=t;i++)f[n][i]=0;
    for(int i=1;i<=n;i++)f[i][0]=dis[i][n]+x;
    for(int i=1;i<=m;i++)for(int j=0;j<=t;j++)g[i][j]=c[i]+f[b[i]][0]*suf[i][j];
    //for(int i=1;i<=n;i++)printf("f[%d][0]=%.5f\n", i,f[i][0]);

    int l=1,r=t;  
    solve(l,r);
    printf("%.8f\n", f[1][t]);
}