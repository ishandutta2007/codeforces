#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll N = 1e5 + 3;
const ll INF = 1e18;

ll n;
string s, t;
vector<ll> v[26];

struct Fenwick{
    ll a[N], n;

    void init(ll n){
        this->n = n;
        fill(a, a + n + 1, 0);
        for(ll i = 1; i < n; ++i)
            update(i, 1);
    }
    void update(ll i, ll v){
        for(++i; i <= n; i += i & -i)
            a[i] += v;
    }
    void update(ll l, ll r, ll v){
        update(l, v);
        update(r + 1, -v);
    }
    ll query(ll i){
        ll ans = 0;
        for(++i; i >= 1; i -= i & -i)
            ans += a[i];
        return ans;
    }
} f;

void solve(){
    cin >> n;
    cin >> s >> t;

    for(ll i = 0; i < 26; ++i)
        v[i].clear();

    for(ll i = n - 1; i >= 0; --i)
        v[s[i] - 'a'].push_back(i);

    f.init(n);

    ll curr = 0, ans = INF;
    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < t[i] - 'a'; ++j){
            if(!v[j].empty()){
                //cout << curr << " " << v[j].back() << "\n";
                check_min(ans, curr + f.query(v[j].back()));
            }
        }
        if(v[t[i] - 'a'].empty())
            break;
        curr += f.query(v[t[i] - 'a'].back());
        f.update(v[t[i] - 'a'].back(), n - 1, -1);
        //cout << v[t[i] - 'a'].back() << " i\n";
        v[t[i] - 'a'].pop_back();
    }

    if(ans == INF)
        ans = -1;
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
        solve();
}