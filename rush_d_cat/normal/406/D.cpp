#include <iostream>
const int N=1000000+10;
using namespace std;
typedef long long LL;
int n;LL x[N],y[N],nex[2][N];
int par[N][22];
const double INF = 1e16;
pair<double,int> stk[N];
double slope(int i,int j) {
    return 1.0*(y[j]-y[i])/(x[j]-x[i]);
}

int ok(int x,int end){
    if(x>end) return 0;
    if(x==end)return 1;
    for(int i=20;i>=0;i--) {
        if(par[x][i]<=end) {
            x=par[x][i];
        }
    }
    return x==end;
}
int go(int x,int k){
    for(int i=20;i>=0;i--){
        if(k>>i&1) x=par[x][i];
    }
    return x;
}
int lca(int x,int y){
    int l=-1,r=n;
    if(x<y)swap(x,y);
    while(r-l>1) {
        int mid=(l+r)>>1;
        int pos=go(x,mid);
        //printf("x=%d, dis=%d pos=%d\n", x,mid,pos);
        if(ok(y,pos)) {
            r=mid;
        } else {
            l=mid;
        }
    } 
    //printf("r=%d, from=%d, to=%d\n", r,x,go(x,r));
    return go(x,r);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&x[i],&y[i]);
    }

    int top=0;
    stk[top=1] = make_pair(-INF,n);
    for(int i=n-1;i>=1;i--){
        double k;
        while(top && (k=slope(i,stk[top].second)) < stk[top].first) -- top;
        nex[0][i] = stk[top].second;
        stk[++top] = make_pair(k,i);
        //printf("i=%d, nex0=%d\n", i,nex[0][i]);
    }       

    for(int i=1;i<=n;i++) {
        par[i][0]=nex[0][i];
       // printf("$ %d %d\n", i,par[i][0]);
    } par[n][0]=n;

    for(int j=1;j<=20;j++)for(int i=1;i<=n;i++)par[i][j]=par[par[i][j-1]][j-1];
    //printf("# %d\n", go(1,1));return 0;
    int m; scanf("%d",&m);
    while(m--) {
        int a,b; scanf("%d%d",&a,&b);
        printf("%d ", lca(a,b));
    }

}