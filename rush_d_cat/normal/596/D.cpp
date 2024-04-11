#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2002;
int n,h;double p;
int a[N];
double dp[N][N][2][2];
bool vis[N][N][2][2];
int nex[N],pre[N];

double solve(int l,int r,int L,int R) {
    if(l>r) return 0;
    if(vis[l][r][L][R]) return dp[l][r][L][R]; vis[l][r][L][R]=1;
    double ans=0;

    //L, L
    if(L==0) {
        int lb = a[l-1];double tmp = min(a[l]-lb, h);
        ans += (l==r?1:0.5) * p * (tmp+solve(l+1,r,0,R));
    } else {
        int lb = a[l-1]+h;double tmp = min(a[l]-lb, h);
        ans += (l==r?1:0.5) * p * (tmp+solve(l+1,r,0,R));
    }
    //printf("dp[%d][%d][%d][%d]=%.5f\n", l,r,L,R,ans);
    //L, R
    if(l!=r) {
        int pos = nex[l]+1; double tmp=a[nex[l]]-a[l]+h;
        if(pos>r) {
            tmp = a[r]-a[l];
            if(R==1) {
                int rb=a[r+1]; tmp+=min(rb-a[r],h);
            } else {
                int rb=a[r+1]-h;tmp+=min(rb-a[r],h);
            }
        }
        ans += 0.5 * (1-p) * (tmp+solve(pos,r,1,R));
    }
    //printf("dp[%d][%d][%d][%d]=%.5f\n", l,r,L,R,ans);
    //R, L
    if(l!=r) {
        int pos = pre[r]-1; double tmp=a[r]-a[pre[r]]+h;
        if(pos<l) {
            //printf("ok\n");
            tmp = a[r]-a[l]; 
            if(L==0) {
                //printf("tmp=%.5f\n", tmp);
                int lb=a[l-1]; tmp+=min(a[l]-lb,h);
            } else {
                int lb=a[l-1]+h;tmp+=min(a[l]-lb,h);
            }
        }
        ans += 0.5 * p * (tmp+solve(l,pos,L,0));
    }
    //printf("dp[%d][%d][%d][%d]=%.5f\n", l,r,L,R,ans);
    //R,R
    if(R==1) {
        int rb = a[r+1]; double tmp=min(rb-a[r], h);
        ans += (l==r?1:0.5) * (1-p) * (tmp+solve(l,r-1,L,1));
    } else {
        int rb = a[r+1]-h; double tmp=min(rb-a[r],h);
        ans += (l==r?1:0.5) * (1-p) * (tmp+solve(l,r-1,L,1));
    }
    //printf("dp[%d][%d][%d][%d]=%.5f\n", l,r,L,R,ans);
    return dp[l][r][L][R] = ans;
}
int main() {
    scanf("%d%d%lf",&n,&h,&p);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    a[0]=-1e9,a[n+1]=1e9;
    nex[n+1]=n+1, pre[0]=0;
    for(int i=n;i>=1;i--) {
        if(a[i]+h>a[i+1]) nex[i]=nex[i+1];
        else nex[i]=i;
        //printf("nex[%d]=%d\n", i,nex[i]);
    }
    for(int i=1;i<=n;i++) {
        if(a[i]-h<a[i-1]) pre[i]=pre[i-1];
        else pre[i]=i;
        //printf("pre[%d]=%d\n", i,pre[i]);
    }
    printf("%.8f\n", solve(1,n,0,0));
}