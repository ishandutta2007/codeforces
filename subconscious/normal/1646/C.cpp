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
const int N=1e6+5,inf=1e9+7;
int T,top;
ll n,p[N];
int main(){
    p[1]=6;top=1;
    for(;;){
        ++top;p[top]=p[top-1]*(top+2);
        if(p[top]>1e12){
            --top;break;
        }
    }
    //printf("%d %lld\n",top,p[top]);
    for(scanf("%d",&T);T--;){
        scanf("%lld",&n);
        int ans=N;
        for(int mk=0;mk<1<<top;++mk){
            ll tmp=0;
            rep(i,top)if(mk&(1<<(i-1)))tmp+=p[i];
            if(n>=tmp)ans=min(ans,__builtin_popcountll(mk)+__builtin_popcountll(n-tmp));
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*


*/