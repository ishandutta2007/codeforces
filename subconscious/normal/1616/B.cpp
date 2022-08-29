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
char s[N];
int n,T;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        scanf("%s",s+1);
        if(n>=2&&s[1]==s[2]){
            putchar(s[1]);putchar(s[1]);
            puts("");
            continue;
        }
        int now=1;
        while(now+1<=n&&s[now]>=s[now+1])++now;
        rep(i,now)putchar(s[i]);
        for(int i=now;i;--i)putchar(s[i]);
        puts("");
    }
    return 0;
}
/*


*/