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
const int N=1e6+5,M=33,inf=1e9+7;
int n,m;
ll ans;
bool in[N],is[N*M];
int cnt[M];
int main(){
    scanf("%d%d",&n,&m);
    int tot=0;
    rep(i,30){
        rep(j,m){
            if(!is[i*j])++tot;
            is[i*j]=1;
        }
        cnt[i]=tot;
    }
    ans=1;
    for(int i=2;i<=n;++i)if(!in[i]){
        int cap=1;
        for(ll x=(ll)i*i;x<=n;x*=i){
            in[x]=1;
            ++cap;
        }
        ans+=cnt[cap];
    }
    printf("%lld\n",ans);
    return 0;
}
/*


*/