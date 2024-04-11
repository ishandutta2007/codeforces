#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fr first
#define se second
#define pb push_back
#define inf 1e9
#define INF 1e18
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<class T>inline void chkmin(T&x,T y){if(y<x)x=y;}
template<class T>inline void chkmax(T&x,T y){if(x<y)x=y;}

#define N 305

int a[N], c[N];
vi v, w;
map <int, int> mp;

int main() {
    int n, i, j, d;
    scanf("%d", &n);
    for(i = 1; i <= n; i ++) scanf("%d", a + i);
    for(i = 1; i <= n; i ++) scanf("%d", c + i);
    mp[0] = 0;
    v.pb(0);
    for(i = 1; i <= n; i ++) {
        for(j = 0; j < v.size(); j ++) {
            d = __gcd(a[i], v[j]);
            if(!mp.count(d)) {
                w.pb(d);
                mp[d] = mp[v[j]] + c[i];
            }
            else chkmin(mp[d], mp[v[j]] + c[i]);
        }
        for(j = 0; j < w.size(); j ++) v.pb(w[j]);
        w.clear();
    }
    if(mp.count(1)) printf("%d", mp[1]);
    else puts("-1");
}