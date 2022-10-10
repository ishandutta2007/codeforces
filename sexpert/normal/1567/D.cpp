#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector<int> cnt;
    int n, s;
    cin >> s >> n;
    while(s) {
        cnt.push_back(s % 10);
        s /= 10;
    }
    while(accumulate(cnt.begin(), cnt.end(), 0) < n) {
        for(int i = 1; i < cnt.size(); i++) {
            if(cnt[i]) {
                cnt[i]--;
                cnt[i - 1] += 10;
                break;
            }
        }
    }
    int sz = cnt.size();
    vector<vector<int>> v(n, vector<int>(sz));
    int p = 0;
    for(int i = 0; i < n; i++) {
        while(cnt[p] == 0)
            p++;
        v[i][p]++;
        cnt[p]--;
    }
    for(int j = 0; j < sz; j++) {
        for(int i = 0; i < n; i++) {
            while(v[i][j] < 10 && cnt[j]) {
                v[i][j]++;
                cnt[j]--;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        auto num = v[i];
        while(num.back() == 0)
            num.pop_back();
        reverse(num.begin(), num.end());
        for(auto &d : num)
            cout << d;
        cout << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}