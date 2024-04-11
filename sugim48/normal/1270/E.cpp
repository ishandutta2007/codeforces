#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

vector<int> f(vector<ll> x, vector<ll> y) {
    int N = x.size();
    vector<int> v;
    rep(i, N) if ((x[i] + y[i]) % 2 == 0) v.pb(i);
    int V = v.size();
    if (1 <= V && V <= N - 1) return v;
    if (V == 0) rep(i, N) x[i]++;
    rep(i, N) {
        ll u = (x[i] + y[i]) / 2;
        ll v = (x[i] - y[i]) / 2;
        x[i] = u; y[i] = v;
    }
    return f(x, y);
}

int main() {
    int N; cin >> N;
    vector<ll> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    vector<int> v = f(x, y);
    int V = v.size();
    cout << V << endl;
    rep(k, V) cout << v[k] + 1 << (k + 1 < V ? ' ' : '\n');
}