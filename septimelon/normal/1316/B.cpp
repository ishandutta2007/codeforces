#include <bits/stdc++.h>

using namespace std;

char getelem(string& s, string& sr, int k, int i) {
    int n = s.size();
    if (i < n + 1 - k) {
        return s[k - 1 + i];
    }
    if ((n - k) % 2 == 1) {
        return s[i - (n + 1 - k)];
    }
    return sr[i];
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string sr = s;
    reverse(sr.begin(), sr.end());
    vector<int> cand;
    vector<int> ncand;
    for (int i = 1; i <= n; ++i) {
        cand.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        ncand.push_back(cand[0]);
        for (int j = 1; j < cand.size(); ++j) {
            if (getelem(s, sr, cand[j], i) < getelem(s, sr, ncand[0], i)) {
                ncand.clear();
                ncand.push_back(cand[j]);
            } else if (getelem(s, sr, cand[j], i) == getelem(s, sr, ncand[0], i)) {
                ncand.push_back(cand[j]);
            }
        }
        cand = ncand;
        ncand.clear();
    }
    for (int i = 0; i < n; ++i) {
        cout << getelem(s, sr, ncand[0], i);
    }
    cout << "\n" << ncand[0] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}