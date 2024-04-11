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
const int N=105;
int a[N],n,T;
set<int>s;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        s.clear();
        rep(i,n){
            scanf("%d",a+i);
            if(s.find(a[i])!=s.end())s.insert(-a[i]);
            else s.insert(a[i]);
        }
        printf("%d\n",(int)s.size());
    }
    return 0;
}
/*


*/