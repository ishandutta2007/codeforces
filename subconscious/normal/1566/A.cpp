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
const int N=3e6+5,mod=1e9+7;
int T,n,m;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);
        printf("%d\n",m/((n+2)/2));
    }

    return 0;
}
/*
XFOF.XFOFX
XFOFXFOF
6+10+12
9+7
*/