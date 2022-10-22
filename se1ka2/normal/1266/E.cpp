#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
 
int main()
{
    int n;
    cin >> n;
    ll a[200005];
    ll x = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        x += a[i];
    }
    int q;
    cin >> q;
    int g[200005] {0};
    ll r = 0;
    map<P, int> mp;
    for(int i = 0; i < q; i++){
        int s, t, u;
        scanf("%d %d %d", &s, &t, &u);
        int v = mp[P(s, t)];
        if(v){
            if(g[v] <= a[v]) r--;
            g[v]--;
        }
        if(u){
            g[u]++;
            if(g[u] <= a[u]) r++;
        }
        mp[P(s, t)] = u;
        printf("%lld\n", x - r);
    }
}