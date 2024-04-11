#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
vector<int> A, B, pows = {1}, logi = {0, 0};
int n;
const int mx = 500050;
int ST[mx][22];

void build() {
    for (int i = 0; i < 22; i++) {
        pows.pb(pows.back() * 2);
    }
    for (int i = 2; i < mx + 3; i++) {
        logi.pb(1 + logi[i / 2]);
    }
    for (int i = 0; i < n; i++) {
        ST[i][0] = A[i];
    }
    for (int lg = 1; lg < 22; lg++) {
        for (int i = 0; i < n; i++) {
            ST[i][lg] = ST[i][lg - 1];
            if (i >= pows[lg - 1]) {
                ST[i][lg] = min(ST[i][lg], ST[i - pows[lg - 1]][lg - 1]);
            }
        }
    }
}

int ans(int l, int r) {
    int lg = logi[r - l + 1];
    return min(ST[r][lg], ST[l + pows[lg] - 1][lg]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    A.resize(n);
    B.resize(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    vector<int> left(n);
    left[0] = -1;
    build();
    for (int i = 1; i < n; i++) {
        int l = -1;
        int r = i;
        while (r - l > 1) {
            int m = (l + r) / 2;
            int mim = ans(m, i - 1);
            if (mim <= A[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        left[i] = l;
    }
    vector<int> S(n);
    S[0] = A[0];
    for (int i = 1; i < n; i++) {
        if (left[i] == -1) {
            S[i] = (i + 1) * A[i];
        } else {
            S[i] = S[left[i]] + A[i] * (i - left[i]);
        }
    }
    vector<int> S2 = S;
    S = {};
    S.resize(n);
    left = {};
    left.resize(n);
    reverse(A.begin(), A.end());
    left[0] = -1;
    for (int i = 1; i < n; i++) {
        int l = -1;
        int r = i;
        while (r - l > 1) {
            int m = (l + r) / 2;
            int mim = ans(n - 1 - (i - 1), n - 1 - m);
            if (mim <= A[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        left[i] = l;
    }
    S[0] = A[0];
    for (int i = 1; i < n; i++) {
        if (left[i] == -1) {
            S[i] = (i + 1) * A[i];
        } else {
            S[i] = S[left[i]] + A[i] * (i - left[i]);
        }
    }
    reverse(S.begin(), S.end());
    reverse(A.begin(), A.end());
    vector<int> kek(n);
    pair<int, int> mj = {-1, -1};
    for (int i = 0; i < n; i++) {
        kek[i] = S[i] + S2[i] - A[i];
        mj = max(mj, {kek[i], i});
    }
    int j = mj.second;
    vector<int> ans(n);
    ans[j] = A[j];
    for (int i = j - 1; i >= 0; i--) {
        ans[i] = min(A[i], ans[i + 1]);
    }
    for (int i = j + 1; i < n; i++) {
        ans[i] = min(A[i], ans[i - 1]);
    }
    for (auto p : ans) cout << p << ' ';
    return 0;
}