#include <bits/stdc++.h>
using namespace std;
bool D = false;
const int INF = (int)1e9 + 34;
typedef long long ll;

int kek(vector<int> a, vector<int> b) {
    for (int i = 0; i < 3; i++) {
        int dif = min(a[i], b[i]);
        a[i] -= dif;
        b[i] -= dif;
        if (i == 2) continue;
        dif = min(b[i], a[i + 1]);
        b[i] -= dif;
        a[i + 1] -= dif;
    }
    return accumulate(a.begin(), a.end(), 0);
}

int getMin(const vector<int> &a, const vector<int> &b) {
    auto seg = [](const vector<int> &v, int l, int r) {
        return vector<int>(v.begin() + l, v.begin() + r);
    };
    int k = min(kek(seg(a, 0, 3), seg(b, 0, 3)), kek(seg(a, 1, 4), seg(b, 1, 4)));
    k = min(k, kek(seg(a, 2, 5), seg(b, 2, 5)));
    return k;
}

int getMax(vector<int> a, vector<int> b) {
    int ans = 0;
    for (int i = 0; i < 3; i++) ans += min(a[i], b[i + 1]);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(3), b(3);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int i = 0; i < 3; i++) {
        a.push_back(a[i]);
        b.push_back(b[i]);
    }
    cout << getMin(a, b) << " " << getMax(a, b) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    D = true;
    t = 5;
#else

#endif
    while (t--) {
        solve();
    }
}