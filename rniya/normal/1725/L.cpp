#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> compress(vector<ll> v) {
    auto u = v;
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    return u;
}

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(ll pos, ll dif) {
        for (; pos < (int)s.size(); pos |= pos + 1)
            s[pos] += dif;
    }
    ll query(int pos) {
        ll res = 0;
        for (; pos > 0; pos &= pos - 1)
            res += s[pos - 1];
        return res;
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &x : A)
        cin >> x;

    vector<ll> B(N + 1, 0);
    for (int i = 0; i < N; i++)
        B[i + 1] = B[i] + A[i];
    auto C = compress(B);
    int n = C.size();
    for (auto &x : B)
        x = lower_bound(C.begin(), C.end(), x) - C.begin();
    if (B.front() != 0 or B.back() != n - 1) {
        cout << -1 << "\n";
        return 0;
    }
    FT ft(n);
    ll ans = 0;
    for (int i = 1, cur = 0; i < N; i++, cur++) {
        ans += cur - ft.query(B[i] + 1);
        ft.update(B[i], 1);
    }
    cout << ans << "\n";
    return 0;
}