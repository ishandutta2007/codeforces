#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuckyzx
#define y0 fuckyxc
#define x1 fuckxzc
#define y1 fucxyzc
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e6+5;
const ld eps=1e-12;
struct node{
    int x,y;
}w[N];
bool cmp(node p,node q){return p.x<q.x;}
int tc,n,a[N],p[N];
ld C,T,d[105][1005];
void upd(ld&x,ld y){if(x>y)x=y;}
int main(){
    for(scanf("%d",&tc);tc--;){
        scanf("%d",&n);
        scanf("%Lf%Lf",&C,&T);
        rep(i,n)scanf("%d%d",&w[i].x,&w[i].y);
        sort(w+1,w+n+1,cmp);
        for(int i=0;i<=n;++i)for(int j=0;j<=i*10;++j)d[i][j]=1e50;
        d[0][0]=0;
        rep(i,n){for(int j=i-1;j>=0;--j)for(int k=j;k<=j*10;++k)
            upd(d[j+1][k+w[i].y],(d[j][k]+w[i].x)/.9L);
    }
        int ans=0;
        for(int j=0;j<=n;++j)for(int k=j;k<=j*10;++k){
            ld t=(sqrt(d[j][k]*C)-1)/C;
            if(t<0)t=0;
            t=t+d[j][k]/(1+C*t);
            if(t+j*10<=T&&ans<k)ans=k;
        }
        printf("%d\n",ans);
    }
    return 0;
}