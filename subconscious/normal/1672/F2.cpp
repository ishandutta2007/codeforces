#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
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
typedef vector<int> vi;
const int N=2e5+5,inf=1e9+7;
int T,n,a[N],b[N],d[N],tmp[N],mx;
vi g[N];
int q[N],l,r,pos[N];
bool check(){
    int tl=1;while(d[tl]!=mx)++tl;
    for(int x:g[tl])--d[x];
    l=r=0;
    rep(i,n)if(g[i].size()>0&&d[i]==0)q[++r]=i;
    int cnt=0;rep(i,n)if(g[i].size()>0)++cnt;
    while(l<r){
        int x=q[++l];
        for(int v:g[x]){
            --d[v];
            if(d[v]==0){
                q[++r]=v;
            }
        }
    }
    if(r!=cnt)return 0;
    rep(i,cnt)pos[q[i]]=i;
    for(int i=1,j;i<=cnt;i=j+1){
        j=i;while(tmp[q[j]]!=mx)++j;
        for(int k=i;k<j;++k)for(int v:g[q[k]])if(pos[v]>j)return 0;
    }
    return 1;
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)g[i].clear(),d[i]=0;
        rep(i,n)scanf("%d",a+i),++d[a[i]];
        rep(i,n)scanf("%d",b+i),g[a[i]].pb(b[i]);
        rep(i,n)tmp[i]=d[i];
        mx=0;
        rep(i,n)mx=max(mx,d[i]);
        puts(check()?"AC":"WA");
    }
    return 0;
}
/*
10 5
2 8
6 7
3 7
2 10
7 10
9 5
9 1
5 3
4 5
 
6 5
1 5
2 1
3 5
4 3
6 5
*/