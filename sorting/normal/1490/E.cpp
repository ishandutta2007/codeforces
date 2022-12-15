#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 2e5 + 3;

ll n;
pair<ll, ll> a[N];

void solve(){
    cin >> n;
    for(ll i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a, a + n);

    vector<ll> curr;
    ll sum = 0;
    for(ll i = 0; i < n; ++i){
        if(sum < a[i].first){
            sum += a[i].first;
            curr.clear();
            curr.push_back(a[i].second);
        }
        else{
            sum += a[i].first;
            curr.push_back(a[i].second);
        }
    }

    sort(curr.begin(), curr.end());
    cout << curr.size() << "\n";
    for(ll x: curr)
        cout << x << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--) solve();
}