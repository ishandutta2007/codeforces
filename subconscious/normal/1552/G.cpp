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
const int N=105+5,mod=998244353;
int n,k,q[N],J[N][N];
int a[N][N],cnt[N][3];
bool flag,f[3];
void dfs(int now){
    if(now==k+1){
        f[0]=f[1]=f[2]=0;
        rep(i,n){
            if((a[k][i]<=0)&&(f[1]||f[2])){flag=1;return;}
            f[a[k][i]+1]=1;
        }
        return;
    }
    cnt[now][0]=cnt[now][1]=cnt[now][2]=0;
    rep(i,q[now])++cnt[now][a[now-1][J[now][i]]+1];
    rep(j,n)a[now][j]=a[now-1][j];
    rep(j,q[now])
        if(j<=cnt[now][0])a[now][J[now][j]]=-1;
        else a[now][J[now][j]]=1;
    dfs(now+1);
    for(int i=1;i<=cnt[now][1];++i){
        a[now][J[now][cnt[now][0]+i]]=-1;
        dfs(now+1);
    }
}
int main(){
    scanf("%d%d",&n,&k);
    rep(i,k){
        scanf("%d",q+i);
        rep(j,q[i])scanf("%d",J[i]+j);
    }
    flag=0;
    rep(i,n)a[0][i]=0;
    dfs(1);
    puts(flag?"REJECTED":"ACCEPTED");
    return 0;
}