#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    vector<vector<ll>> cou(s.size() + 1, vector<ll>(30, 0LL));
    for (int i = 0; i < s.size(); ++i) {
        ++cou[0][s[i] - 'a'];
    }
    vector<vector<ll>> cc(30, vector<ll>(30, 0LL));
    for (int i = 0; i < s.size(); ++i) {
        int curc = s[i] - 'a';
        --cou[i][curc];
        cou[i + 1] = cou[i];
        for (int j = 0; j < ('z' - 'a') + 1; ++j) {
            cc[curc][j] += cou[i][j];
        }
    }
    ++cou[0][s[0] - 'a'];
    ll maxc = 0LL;
    for (int i = 0; i < ('z' - 'a') + 1; ++i) {
        maxc = max(maxc, cou[0][i]);
        for (int j = 0; j < ('z' - 'a') + 1; ++j) {
            maxc = max(maxc, cc[i][j]);
        }
    }
    cout << maxc << "\n";
    return 0;
}