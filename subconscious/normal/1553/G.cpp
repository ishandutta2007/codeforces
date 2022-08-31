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
const int N=1e6+5,mod=1e9+7;
int pri[N/3],top,nxt[N];
bool is[N];
int a[N],n,q;
int f[N],ft[N];
int fa(int x){return f[x]==x?x:f[x]=fa(f[x]);}
vector<int>tmp;
set<pr>dic;
int main(){
    for(int i=2;i<N;++i){
        if(!is[i]){
            pri[++top]=i;
            nxt[i]=i;
        }
        for(int j=1;j<=top&&(ll)pri[j]*i<N;++j){
            is[pri[j]*i]=1;
            nxt[pri[j]*i]=pri[j];
            if(i%pri[j]==0)break;
        }
    }

    scanf("%d%d",&n,&q);
    rep(i,n)f[i]=i;
    rep(i,n){
        scanf("%d",a+i);
        int now=a[i];
        while(now>1){
            int p=nxt[now];
            if(ft[p]==0)ft[p]=i;
            int x=fa(i),y=fa(ft[p]);
            f[x]=y;
            now/=p;
        }
    }
    
    rep(i,n){
        tmp.clear();
        tmp.pb(fa(i));
        int now=a[i]+1;
        while(now>1){
            int p=nxt[now];
            if(ft[p]!=0)tmp.pb(fa(ft[p]));
            now/=p;
        }
        for(int u:tmp)
            for(int v:tmp)
                dic.insert(mp(u,v));
    }

    rep(i,q){
        int u,v;scanf("%d%d",&u,&v);
        u=fa(u),v=fa(v);
        if(u==v)puts("0");
        else if(dic.find(mp(u,v))!=dic.end())puts("1");
        else puts("2");
    }
    return 0;
}