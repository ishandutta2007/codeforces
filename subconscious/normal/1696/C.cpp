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
typedef pair<ll,ll> pii;
typedef vector<int> vi;
const int N=3e5+5,mod=1e9+7;
int n,m,T,k;
vector<pii>a,b;
void rd(int siz,vector<pii>&a){
    a.clear();
    rep(i,siz){
        int x;scanf("%d",&x);
        pii t=mp(x,1);
        while(t.st%m==0)t.st/=m,t.nd*=m;
        if(a.size()>0&&a.back().st==t.st)a.back().nd+=t.nd;else a.pb(t);
    }
}
bool check(){
    if(a.size()!=b.size())return 0;
    rep(i,a.size())if(a[i-1]!=b[i-1])return 0;
    return 1;
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);
        rd(n,a);
        scanf("%d",&k);
        rd(k,b);
        puts(check()?"Yes":"No");
    }
    return 0;
}
/*
3 
1 -1 
1 1
-1 2
*/