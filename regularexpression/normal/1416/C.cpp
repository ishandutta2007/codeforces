#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

int n, a[N];

int X = 0;

long long get01(const vector<int> &A) {
    int cnt = 0;
    long long res = 0;
    for (const auto &x : A) {
        if (x == 0)
            res += cnt;
        else
            ++cnt;
    }

    return res;
}

long long solve(int bit) {
    vector<pair<int, int> > C;
    for (int i = 0; i < n; ++i)
        C.emplace_back(a[i] >> 1, i);
    sort(C.begin(), C.end());

    long long sum0 = 0, sum1 = 0;
    vector<int> A;
    for (int i = 0; i < n; ++i) {
        A.push_back(a[C[i].second] & 1);

        if (i + 1 == (int)C.size() || C[i].first != C[i + 1].first) {
            sum0 += get01(A);

            for (auto &x : A)
                x ^= 1;

            sum1 += get01(A);
            A.clear();
        }
    }

    if (sum1 < sum0)
        X += 1 << bit;

    return min(sum0, sum1);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a[n] = -1;

    long long ans = 0;
    for (int bit = 0; bit < 32; ++bit) {
        ans += solve(bit);

        for (int i = 0; i < n; ++i)
            a[i] >>= 1;
    }

    cout << ans << " " << X << '\n';
    return 0;
}