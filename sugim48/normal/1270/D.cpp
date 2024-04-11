#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

i_i ask(vector<int> a) {
    cout << '?';
    for (int i: a) cout << ' ' << i + 1;
    cout << endl;
    int i, x;
    cin >> i;
    if (i == -1) exit(0);
    cin >> x;
    return i_i(i - 1, x);
}

int main() {
    int N, K;
    cin >> N >> K;
    N = K + 1;
    vector<int> xs;
    rep(i0, N) {
        vector<int> a;
        rep(i, N) if (i != i0) a.pb(i);
        int k, x;
        tie(k, x) = ask(a);
        xs.pb(x);
    }
    int mi = INT_MAX, ma = INT_MIN;
    for (int x: xs) {
        mi = min(mi, x);
        ma = max(ma, x);
    }
    int ans = 0;
    for (int x: xs) if (x == ma) ans++;
    cout << "! " << ans << endl;
}