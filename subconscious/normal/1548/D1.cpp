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
const int N=3e6+5,mod=1e9+7;
int cnt[2][2],inn[2][2];
int n;
pr typ[3];
ll ans;
void dfs(int x,int y,int now){
    if(x==2){
        if(now!=3)return;
        ll ret=1;
        int top=0;
        for(int i=0;i<4;++i){
            int xx=i&1,yy=i>>1;
            for(int j=0;j<inn[xx][yy];++j)
                ret=ret*(cnt[xx][yy]-j)/(j+1);
            for(int j=0;j<inn[xx][yy];++j)
                typ[top++]=mp(xx,yy);
        }
        int tmp=0;
        for(int i=0;i<3;++i)
            tmp^=(typ[i].st!=typ[(i+1)%3].st||typ[i].nd!=typ[(i+1)%3].nd);
        if(tmp==0){
            ans+=ret;
        }return;
    }
    for(int i=0;i+now<=3&&i<=cnt[x][y];++i){
        inn[x][y]=i;
        if(y==0)dfs(x,1,i+now);
        else dfs(x+1,0,i+now);
    }
}
int main(){
    scanf("%d",&n);
    rep(i,n){
        int x,y;scanf("%d%d",&x,&y);
        x/=2,y/=2;
        ++cnt[x&1][y&1];
    }
    ans=0;
    dfs(0,0,0);
    printf("%lld\n",ans);
    return 0;
}
/*

*/