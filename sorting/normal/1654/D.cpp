#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;
const ll MOD = 998244353;

int n;
vector<array<ll, 3>> adj[N];

vector<pair<int, int>> primes[N];
int cnt[N], mn[N];
ll sum;

ll fast_pow(ll base, ll exp){
    if(!exp) return 1ll;
    if(exp & 1) return base * fast_pow(base, exp - 1) % MOD;
    ll t = fast_pow(base, exp >> 1);
    return t * t % MOD;
}

void sieve(){
    for(int i = 2; i < N; ++i){
        if(primes[i].size()) continue;
        for(int j = i; j < N; j += i){
            int x = j;
            pair<int, int> p{i, 0};
            while(x % i == 0){
                x /= i;
                ++p.second;
            }
            primes[j].push_back(p);
        }
    }
}

void dfs(int u, int p = -1, ll curr = 1){
    // cout << "dfs " << u << endl;

    sum += curr;
    if(sum >= MOD) sum -= MOD;

    for(auto [to, a, b]: adj[u]){
        if(to == p)
            continue;

        for(auto [prime, cnt_prime]: primes[a])
            cnt[prime] += cnt_prime;
        for(auto [prime, cnt_prime]: primes[b])
            cnt[prime] -= cnt_prime;

        for(auto [prime, cnt_prime]: primes[b])
            check_min(mn[prime], cnt[prime]);

        dfs(to, u, curr * a % MOD * fast_pow(b, MOD - 2) % MOD);

        for(auto [prime, cnt_prime]: primes[a])
            cnt[prime] -= cnt_prime;
        for(auto [prime, cnt_prime]: primes[b])
            cnt[prime] += cnt_prime;
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        adj[i].clear();
    for(int i = 1; i <= n - 1; ++i){
        int a, b, x, y;
        cin >> x >> y >> a >> b;
        adj[x].push_back({y, b, a});
        adj[y].push_back({x, a, b});
    }

    fill(cnt + 1, cnt + 1 + n, 0);
    fill(mn + 1, mn + 1 + n, 0);
    sum = 0;
    dfs(1);

    for(int i = 1; i <= n; ++i){
        if(mn[i] < 0){
            sum *= fast_pow(i, -mn[i]);
            sum %= MOD;
        }
    }

    cout << sum << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    cin >> t;
    
    while(t--){
        solve();
    }
}