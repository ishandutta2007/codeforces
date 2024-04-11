#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int solveRand(int n, const vector<pair<int, int>> &values) {
    vector<ll> v(n, 0);
    ll sum = 0;
    
    for (const auto &it : values) {
        int a = it.first, b = it.second;
        v[a] = b;
        sum += b;
    }

    if (sum > n) return -1;

    for (int it = 0; it < 300; it++) {
        int val = rand() % sum;
        for (int i = 0; i < n; i++) {
            if (v[i] > val) {
                if (v[i] < 2) continue;
                v[(i + 1) % n]++;
                v[(i + n - 1) % n]++;
                v[i] -= 2;
                break;
            } else {
                val -= v[i];
            }
        }
        if (*max_element(v.begin(), v.end()) <= 1)
            return 1;
    }
    return -1;
}

int score(vector<int> v) {
    int sum = 0;
    for (int i = 0; i < (int)v.size(); i++) sum += i * v[i];
    return sum % v.size();
}

void kek() {
    for (int n = 4; n <= 7; n++) {
        set<vector<int>> keks, oks;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) v[i].first = i;
        for (int it = 0; it < 10000; it++) {
            for (int i = 0; i < n; i++) v[i].second = 0;
            for (int i = 0; i < n; i++) v[rand() % n].second++;
            vector<int> kk, mn;
            for (int i = 0; i < n; i++) kk.push_back(v[i].second);
            mn = kk;
            for (int i = 0; i < n; i++) kk.push_back(kk[i]);
            for (int i = 0; i < n; i++)
                mn = min(mn, vector<int>(kk.begin() + i, kk.begin() + i + n));
            reverse(kk.begin(), kk.end());
            for (int i = 0; i < n; i++)
                mn = min(mn, vector<int>(kk.begin() + i, kk.begin() + i + n));
            if (solveRand(n, v) == 1) oks.insert(mn);
            else keks.insert(mn);
        }
        cout << n << ": " << endl;
        cout << "keks:\n";
        for (const auto k : keks) {
            for (int i = 0; i < n; i++) cout << " " << k[i];
            cout << " " << score(k);
            cout << endl;
        }
        cout << "oks:\n";
        for (const auto k : oks) {
            for (int i = 0; i < n; i++) cout << " " << k[i];
            cout << " " << score(k);
            cout << endl;
        }
    }
}
 
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    ll kek = 0, sum = 0;
    int a = 0, b = 1;
    while (k--) {
        cin >> a >> b;
        v.emplace_back(a, b);
        sum += b;
        kek = (kek + (ll)(a-1) * (ll)b) % n;
    }

    ll nid = ((ll)n * (n - 1)) / 2 % n;
    // cout << sum << " " << nid << " " << kek << endl;

    cout << (sum < n || nid == kek ? 1 : -1) << endl;

    //cout << solveRand(n, v) << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // kek();
    // return 0;
    solve();
}