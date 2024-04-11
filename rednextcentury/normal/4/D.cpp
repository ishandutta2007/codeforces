# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll>pll;

const ll maxN = ll(8e5);
const ll smaxN = ll(5e3);
const ll lmaxN = ll(2e6);
const ll oo = ll(1e18);
const ll MOD = ll(1e9) + 7LL;
const ld EPS = 1e-9;

template<typename T>
T Sqr(T x){
    return x * x;
}

struct State{
    ll w, h, id;
    bool operator<(State b){
        return (this -> w == b.w ? (this -> h < b.h ? 1 : 0) : (this -> w < b.w));
    }

    State(){

    }

    State(ll x, ll y, ll z){
        this -> w = x;
        this -> h = y;
        this -> id = z;
    }
};

ll n, w, h;
vector<State>v;
vector<ll>ans;
ll dp[maxN], ind, mx;
ll p[maxN];

void Maximize(ll i, ll j){
    if(v[i].w > v[j].w && v[i].h > v[j].h && dp[i] < dp[j] + 1){
        dp[i] = dp[j] + 1;
        p[i] = j;
    }
}

int main(){

    cin >> n >> w >> h;

    for(ll i = 1; i <= n; ++i){
        dp[i - 1] = 1;
        p[i - 1] = -1;
        ll x, y;
        cin >> x >> y;
        if(x > w && y > h){
            v.push_back(State(x, y, i));
        }
    }
    if(v.size() == 0){
        cout << 0;
        return 0;
    }

    sort(v.begin(), v.end());

    for(ll i = 0; i < v.size(); ++i){

        for(ll j = i - 1; j >= 0; --j){
            if(v[i].w < w || v[i].h < h){
                continue;
            }
            Maximize(i, j);
        }
    }

    for(ll i = 0; i < n; ++i){
        if(dp[i] > mx){
            mx = dp[i], ind = i;
        }
    }
    ans.push_back(v[ind].id);
    while(p[ind] != -1){
        ans.push_back(v[p[ind]].id);
        ind = p[ind];
    }
    reverse(ans.begin(), ans.end());
    while(find(ans.begin(), ans.end(), 0) != ans.end()){
        ans.erase(find(ans.begin(), ans.end(), 0));
    }
    for(ll i = 0; i < ans.size(); ++i){
        if(ans[i] > n){
            ans.erase(ans.begin() + i);
        }
    }

    cout << ans.size() << "\n";
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}