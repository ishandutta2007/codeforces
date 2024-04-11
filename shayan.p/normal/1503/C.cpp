#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

const int maxn = 1e5 + 10;
const ll inf = 1e18;

pii p[maxn];
ll dp[maxn];

ll mnm = inf;
ll lazy = 0;
priority_queue<pll> pq;
multiset<ll> frozen;

void add_to_all(ll x){
    mnm+= x;
    lazy+= x;
    while(!pq.empty() && pq.top().first + lazy >= 0){
        pll p = pq.top();
        pq.pop();
        mnm = min(mnm, p.first + lazy + p.second);
        frozen.erase(frozen.find(pq.top().second));
    }
}
void add(ll shield, ll value){
    if(shield >= 0){
        mnm = min(mnm, value);
        return;
    }
    pq.push({shield - lazy, value});
    frozen.insert(value);
}
ll get_best(){
    if(frozen.empty())
        return mnm;
    return min(mnm, *frozen.begin());
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
        ans+= p[i].second;
    }
    sort(p, p + n);
    add(-p[0].second, dp[0]);    
    for(int i = 1; i < n; i++){
        add_to_all(p[i].first - p[i-1].first);
        dp[i] = get_best();
        add(-p[i].second, dp[i]);
    }
    ans+= dp[n-1];
    return cout << ans << endl, 0;
}