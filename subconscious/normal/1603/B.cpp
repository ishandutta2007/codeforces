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
const int N=1e5+5;
const ld PI=acos(-1),eps=1e-12;
ll T,x,y;
int main(){
    for(scanf("%lld",&T);T--;){
        scanf("%lld%lld",&x,&y);
        if(x>y)printf("%lld\n",x+y);
        else printf("%lld\n",y-(y-x)%x/2);
    }
    return 0;
}
/*
1.000000 -12.904762 40.476190 -28.571429
3.000000 11.607143 -34.424603 22.817460
*/