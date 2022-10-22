#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll a[400002];
vector<ll> v[400002];
ll now[400005];

int main()
{
    ll n, k;
    cin >> n >> k;
    unordered_map<ll, ll> ts;
    ll l = 1;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(ts[a[i]] == 0){
            ts[a[i]] = l;
            l++;
        }
        v[ts[a[i]]].push_back(i);
    }
    map<ll, ll> mp;
    priority_queue<P, vector<P>, greater<P>> que;
    for(ll i = 1; i < l; i++){
        if((ll)v[i].size() >= k){
            v[i].push_back(n);
            mp[i] = v[i][k - 1];
            que.push(P(v[i][k - 1], i));
        }
    }
    if((int)que.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    for(ll i = 1; i < l; i++) now[i] = k - 1;
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(que.top().first == n) break;
        while(mp[que.top().second] != que.top().first && que.top().first != n){
            P p = que.top();
            que.pop();
            que.push(P(v[p.second][now[p.second]], p.second));
        }
        ans += n - que.top().first;
        if(mp[ts[a[i]]] || k == 1){
            if(mp[ts[a[i]]] != n){
                now[ts[a[i]]]++;
                mp[ts[a[i]]] = v[ts[a[i]]][now[ts[a[i]]]];
            }
        }
        else mp.erase(ts[a[i]]);
    }
    cout << ans << endl;
}