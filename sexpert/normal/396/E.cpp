#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

const int MAX = 1e6 + 5;
const int INF = 1e9;
int prime[MAX], start[MAX], dis[MAX];
vector<int> adj[MAX], primes;
vector<ii> events[MAX];
ll cnt[MAX];

void sieve() {
    for(int p = 2; p < MAX; p++) {
        if(prime[p])
            continue;
        primes.push_back(p);
        for(int q = p; q < MAX; q += p)
            prime[q] = p;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    for(auto p : primes) {
        int x = p - 1;
        while(x > 1) {
            int q = prime[x];
            while(x % q == 0)
                x /= q;
            adj[p].push_back(q);
        }
    }
    fill(dis, dis + MAX, INF);
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        ll p, a;
        cin >> p >> a;
        cnt[p] = a;
        events[p].push_back({1, a});
    }
    ll k;
    cin >> k;
    reverse(primes.begin(), primes.end());

    for(auto p : primes) {
        if(!cnt[p])
            continue;
        sort(events[p].begin(), events[p].end());
        vector<ii> clean;
        int i = 0;
        ll t = -1, ri = -1, moves = 0;
        while(i < events[p].size()) {
            if(t == -1) {
                t = events[p][i].first;
                ri = max(ri, events[p][i].second);
            }
            else
                ri += events[p][i].second - events[p][i].first + 1;
            ri = min(ri, k);
            if(i == events[p].size() - 1 || events[p][i + 1].first > ri + 1) {
                clean.push_back({t, min(ri, k)});
                t = -1;
                ri = -1;
                moves += clean.back().second - clean.back().first + 1;
            }
            i++;
        }
        cnt[p] -= moves;
        int x = p - 1;
        while(x > 1) {
            int q = prime[x], e = 0;
            while(x % q == 0) {
                x /= q;
                e++;
            }
            for(auto p : clean) {
                ll len = p.second - p.first + 1;
                if(p.first + 1 <= k)
                    events[q].push_back({p.first + 1, min(p.first + len * e, k)});
                cnt[q] += len * e;
            }
        }
    }

    int tot = 0;
    reverse(primes.begin(), primes.end());
    for(auto p : primes)
        if(cnt[p])
            tot++;
    cout << tot << '\n';
    for(auto p : primes)
        if(cnt[p])
            cout << p << " " << cnt[p] << '\n';
}