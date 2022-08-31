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
const int N=1e6+5,mod=998244353;
int n,m;
vi a[2][N];
ll ans;
ll sol(vi &a){
    ll ret=0;
    int siz=sz(a);
    sort(all(a));
    rep(i,siz)ret=ret+(ll)(i-1)*a[i-1]-(ll)(siz-i)*a[i-1];
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,n)rep(j,m){
        int x;scanf("%d",&x);
        a[0][x].pb(i);
        a[1][x].pb(j);
    }
    int mx=1e5;
    rep(i,mx)ans+=sol(a[0][i])+sol(a[1][i]);
    printf("%lld\n",ans);
    return 0;
}
/*
*/