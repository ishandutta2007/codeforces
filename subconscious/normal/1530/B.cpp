#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=25,mod=998244353;
const ld eps=1e-10;
int a[N],n,m,T;
bool is[N][N];
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);
        rep(i,n+1)rep(j,m+1)is[i][j]=0;
        is[1][1]=is[n][1]=is[1][m]=is[n][m]=1;
        rep(i,n)rep(j,m)if(i==1||i==n||j==1||j==m){
            if(is[i][j]==1)continue;
            bool flag=0;
            for(int dx=-1;dx<=1;++dx)for(int dy=-1;dy<=1;++dy)
                if((dx!=0||dy!=0)&&is[i+dx][j+dy]==1){flag=1;break;}
            if(!flag)is[i][j]=1;
        }
        rep(i,n){rep(j,m)printf("%d",(int)is[i][j]);puts("");}
        puts("");
    }
    return 0;
}
/*
*/