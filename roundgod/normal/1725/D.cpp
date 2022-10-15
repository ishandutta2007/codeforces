#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
typedef pair<int,int>pi;
int q,n,m;
int o[maxn],b[maxn];
int cnt[maxn],a[maxn],h[maxn],req[maxn],p[maxn];
vector<int> G[maxn];
void add(int x,int y){
    while (x<maxn) b[x]+=y,x+=x&(-x);
}
int qry(int x){
    int res=0;
    for (int i=16;i>=0;i--){
        if (b[res+(1<<i)]<x){
            res+=(1<<i);
            x-=b[res];
        }
    }
    return res+1;
}
int main(){
    scanf("%d%d",&n,&q);
    for (int i=1;i<=q;i++) scanf("%d",&a[i]);
    int pos=1;
    ll ans=0;
    for (int i=1;;i++){
        int res=min((i+1)/2,n);
        n-=res;
        ans+=(ll)res*i;
        m=max(m,res);
        cnt[res]++;
        if (!n) break;
    }
    printf("%lld\n",ans);
    for (int i=m;i>1;i--) cnt[i-1]+=cnt[i];
    priority_queue<pi,vector<pi>,greater<pi> > Q;
    for (int i=1;i<=m;i++) h[i]=i*2-1,Q.push((pi){i*2-1,i});
    int cc=0;
    while (Q.top().F*2<m*2-1){
        pi tmp=Q.top(); Q.pop();
        int x=tmp.S;
        ++cc;
        if (a[pos]==cc){
            printf("%d\n",h[x]);
            pos++;
        }
        h[x]++; cnt[x]--;
        Q.push((pi){tmp.F*2,x});
    }
    for (int i=1;i<=m;i++) G[cnt[i]].pb(i);
    vector<pi> ord;
    int cw=0;
    while (!Q.empty()){
        pi tmp=Q.top(); Q.pop();
        int u=tmp.S;
        o[++cw]=u; p[u]=cw;
    }
    for (int i=1;i<=m;i++) add(i,1);
    int ncnt=m;
    for (auto x:G[0]) add(p[x],-1),ncnt--;
    for (int i=1;i<=100000;i++){
        while (pos<=q&&a[pos]<=cc+ncnt){
            int tmp=qry(a[pos]-cc);
            int x=o[tmp];
            printf("%d\n",h[x]+i-1);
            pos++;
        }
        cc+=ncnt;
        for (auto x:G[i]) add(p[x],-1),ncnt--;
    }
}