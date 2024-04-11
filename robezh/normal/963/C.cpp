#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;
typedef long long ll;
typedef pair<ll, ll> P;

int n;
ll g = 0;
int cnt = 0;
ll w[N], h[N], c[N];
map<ll, int> mp;
vector<P> ls[N];

int getid(int wid){
    if(mp.count(wid)) return mp[wid];
    return mp[wid] = cnt++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> w[i] >> h[i] >> c[i];
        g = __gcd(g, c[i]);
    }
    for(int i = 0; i < n; i++){
        ls[getid(w[i])].push_back({h[i], c[i] / g});
    }
    for(int i = 0; i < cnt; i++){
        ll gi = 0;
        for(auto p : ls[i]){gi = __gcd(gi, p.second);}
        for(auto &p : ls[i]) p.second /= gi;
        sort(ls[i].begin(), ls[i].end());
    }
    for(int i = 1; i < cnt; i++){
        if(ls[i].size() != ls[i-1].size()) return cout << 0 << endl, 0;
        for(int j = 0; j < ls[i].size(); j++){
            if(ls[i][j] != ls[0][j]) return cout << 0 << endl, 0;
        }
    }
    int res = 0;
    ll i;
    for(i = 1; i * i < g; i++){
        if(g % i == 0) res += 2;
    }
    if(i * i == g) res ++;
    cout << res << endl;
}