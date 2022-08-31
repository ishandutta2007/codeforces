#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=3e6+5,mod=1e9+7;
int n,cnt[N],res;
set<int>st[N];
bool in[N];
int main(){
    scanf("%d",&n);
    rep(i,n-1){
        int x,y;
        scanf("%d%d",&x,&y);
        st[x].insert(y),st[y].insert(x);
    }
    res=n;
    while(res>1){
        int u,v;
        rep(i,n)if(st[i].size()==1){u=i;break;}
        for(int i=u+1;i<=n;++i)if(st[i].size()==1){v=i;break;}
        printf("? %d %d\n",u,v);
        fflush(stdout);
        int ret;
        scanf("%d",&ret);
        if(ret==u||ret==v){printf("! %d\n",ret);return 0;}
        int tmp;
        tmp=*st[u].begin();st[u].clear();st[tmp].erase(u);
        tmp=*st[v].begin();st[v].clear();st[tmp].erase(v);
        in[u]=1,in[v]=1;
        res-=2;
    }
    rep(i,n)if(!in[i]){printf("! %d\n",i);return 0;}
}