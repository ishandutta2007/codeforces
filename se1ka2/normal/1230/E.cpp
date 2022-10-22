#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

map<ll, ll> mp[100002];

ll gcd(ll n, ll m){
    if(m == 0) return n;
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main()
{
    ll n;
    cin >> n;
    ll x[100002];
    for(int i = 0; i < n; i++) cin >> x[i];
    ll a[100002], b[100002];
    vector<ll> v[100002];
    for(ll i = 0; i < n - 1; i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    ll d[100002];
    for(ll i = 0; i < n; i++) d[i] = -1;
    ll ans = 0;
    queue<ll> que;
    que.push(0);
    d[0] = 0;
    mp[0][x[0]] = 1;
    ans = (ans + x[0] * mp[0][x[0]]) % MOD;
    while(que.size()){
        ll now = que.front();
        que.pop();
        for(int next : v[now]){
            if(d[next] == -1){
                d[next] = d[now] + 1;
                que.push(next);
                for(auto itr = mp[now].begin(); itr != mp[now].end(); itr++){
                    mp[next][gcd(itr -> first, x[next])] += itr -> second;
                }
                mp[next][x[next]]++;
                for(auto itr = mp[next].begin(); itr != mp[next].end(); itr++){
                    ans = (ans + ((itr -> first) % MOD) * ((itr -> second) % MOD) % MOD) % MOD;
                }
            }
        }
    }
    cout << ans << endl;
}