#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int n, I;
    cin >> n >> I;
    int k = I * 8 / n;
    if (k > 20) {
        cout << "0\n";
        return;
    }
    k = (1 << k);
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(all(a));
    a.push_back(-1);
    int nn = 0;
    vector<int> num = {0};
    for (int i = 0; i < (int)a.size() - 1; i++) {
        nn++;
        if (a[i] == a[i + 1]) continue;
        num.push_back(nn);
        nn = 0;
    }
    if (k >= (int)num.size() - 1) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i < (int)num.size(); i++) num[i] += num[i - 1];
    int mx = 0;
    for (int i = k; i < (int)num.size(); i++) {
        mx = max(mx, num[i] - num[i - k]);
    }
    cout << n - mx << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 3;
    for (int i = 1; i < T; i++) solve();    
#endif
}