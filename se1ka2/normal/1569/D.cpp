#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

bool bx[1000005], by[1000005];
P p[700005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int x[200005], y[200005];
        for(int i = 0; i < n; i++){
            cin >> x[i];
            bx[x[i]] = true;
        }
        for(int i = 0; i < m; i++){
            cin >> y[i];
            by[y[i]] = true;
        }
        for(int i = 0; i < k; i++){
            int u, v;
            cin >> u >> v;
            p[i] = P(u, v);
        }
        for(int i = 0; i < n; i++) p[i + k] = P(x[i], -1);
        for(int i = 0; i < m; i++) p[i + k + n] = P(-1, y[i]);
        sort(p, p + k + n + m);
        ll ans = 0;
        map<int, int> mp;
        int c = 0;
        for(int i = 0; i < k + n + m; i++){
            if(p[i].first == -1) continue;
            if(bx[p[i].first]){
                mp.clear();
                c = 0;
                continue;
            }
            mp[p[i].second]++;
            c++;
            ans += c - mp[p[i].second];
        }
        for(int i = 0; i < k + n + m; i++) swap(p[i].first, p[i].second);
        sort(p, p + k + n + m);
        mp.clear();
        c = 0;
        for(int i = 0; i < k + n + m; i++){
            if(p[i].first == -1) continue;
            if(by[p[i].first]){
                mp.clear();
                c = 0;
                continue;
            }
            mp[p[i].second]++;
            c++;
            ans += c - mp[p[i].second];
        }
        cout << ans << endl;
        for(int i = 0; i < n; i++) bx[x[i]] = false;
        for(int i = 0; i < m; i++) by[y[i]] = false;
    }
}