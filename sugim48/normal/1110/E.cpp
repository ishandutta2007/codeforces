#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

bool solve(vector<ll> a, vector<ll> b) {
    int N = a.size();
    if (a[0] != b[0]) return false;
    vector<ll> da(N - 1), db(N - 1);
    rep(i, N - 1) da[i] = a[i + 1] - a[i];
    rep(i, N - 1) db[i] = b[i + 1] - b[i];
    sort(all(da));
    sort(all(db));
    return da == db;
}

int main() {
    int N; cin >> N;
    vector<ll> a(N), b(N);
    rep(i, N) scanf("%lld", &a[i]);
    rep(i, N) scanf("%lld", &b[i]);
    cout << (solve(a, b) ? "Yes" : "No") << endl;
}