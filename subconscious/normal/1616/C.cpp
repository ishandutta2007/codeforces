#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
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
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=1e5+5;
int a[N],T,n;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        int ans=min(2,n);
        rep(i,n)rep(j,i-1){
            int now=0;
            rep(k,n)if((ll)(i-k)*a[j]+(ll)(k-j)*a[i]==(ll)a[k]*(i-j))++now;
            ans=max(ans,now);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
/*


*/