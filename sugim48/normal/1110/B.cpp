#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

int main() {
    int N, L, K;
    cin >> N >> L >> K;
    vector<int> a(N);
    rep(i, N) scanf("%d", &a[i]);
    vector<int> v(N - 1);
    rep(i, N - 1) v[i] = a[i + 1] - a[i] - 1;
    sort(all(v));
    int ans = N;
    rep(t, N - K) ans += v[t];
    cout << ans << endl;
}