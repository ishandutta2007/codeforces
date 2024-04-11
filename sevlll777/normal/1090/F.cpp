#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
int ans = 0;

int ask(int i, int j, int k) {
    cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    cin >> ans;
    return ans;
}

int sum4(vector<int> nums) {
    vector<int> X;
    X.pb(ask(nums[1], nums[2], nums[3]));
    X.pb(ask(nums[0], nums[2], nums[3]));
    X.pb(ask(nums[0], nums[1], nums[3]));
    X.pb(ask(nums[0], nums[1], nums[2]));
    sort(X.begin(), X.end());
    return X[3] + X[0];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> C(n);
    int s0 = sum4({1, 2, 3, 4});
    int s1 = sum4({0, 2, 3, 4});
    int s2 = sum4({1, 0, 3, 4});
    int s3 = sum4({1, 2, 0, 4});
    int s4 = sum4({0, 1, 2, 3});
    int s5 = (s0 + s1 + s2 + s3 + s4) / 4;
    C[0] = s5 - s0;
    C[1] = s5 - s1;
    C[2] = s5 - s2;
    C[3] = s5 - s3;
    C[4] = s5 - s4;
    for (int i = 5; i < n; i++) {
        int g = sum4({0, 1, 2, i});
        g -= (C[0] + C[1] + C[2]);
        C[i] = g;
    }
    cout << "! ";
    for (auto x : C) cout << x << ' ';
    cout << endl;
}