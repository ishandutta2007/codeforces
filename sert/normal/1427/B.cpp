#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int score = 0;

    vector<int> a;

    int numL = count(s.begin(), s.end(), 'L');
    k = min(numL, k);

    if (numL == n) {
        cout << max(0, k * 2 - 1) << "\n";
        return;
    }

    int cnt = 0;
    int i = 0;
    while (i < n && s[i] == 'L') i++;
    for (; i < n; i++) {
        if (s[i] == 'L') cnt++;
        else {
            if (cnt > 0) a.push_back(cnt);
            cnt = 0;
            score++;
            if (i > 0 && s[i - 1] == 'W') score++;
        }
    }

    //cout << score << " " << a.size() << " " << a[0] << endl;

    sort(a.begin(), a.end());
    for (int x : a) {
        if (x > k) break;
        score += x * 2 + 1;
        k -= x;
    }
    score += k * 2;
    cout << score << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef SERT
    freopen("a.in", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
        solve();
}