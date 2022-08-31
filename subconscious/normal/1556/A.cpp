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
const int N=1e6+5,mod=1e9+7;
int a[N],c,d,T;
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%d%d",&c,&d);
        if(c%2!=d%2)puts("-1");
        else if(c==0&&d==0)puts("0");
        else if(c==d)puts("1");
        else puts("2");
    }
    return 0;
}
/*


*/