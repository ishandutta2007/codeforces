#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    string t;
    cin >> t;

    int n = s.size();
    int m = t.size();

    map<char, vector<int>> mp;
    for(int i = 0; i < m; i++) {
        mp[t[i]].push_back(i);
    }

    vector<int> pr(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        pr[i] = pr[i - 1] + (pr[i - 1] < t.size() && t[pr[i - 1]] == s[i - 1]);
    }

    vector<int> suf(n + 1, 0);
    suf[n] = 0;
    for(int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + (suf[i + 1] < t.size() && t[m - suf[i + 1] - 1] == s[i]);
    }

    for(int i = 0; i < n; i++) if(!mp[s[i]].empty()) {

        int x = pr[i];
        int y = suf[i + 1];
//        cout << int(upper_bound(mp[s[i]].begin(), mp[s[i]].end(), pr[i]) - mp[s[i]].begin()) << endl;
        int j = int(upper_bound(mp[s[i]].begin(), mp[s[i]].end(), pr[i]) - mp[s[i]].begin()) - 1;
//        cout << j << endl;
//        cout << mp[s[i]].size() << endl;
        j = mp[s[i]][j];


//        cout << i << ' ' << x << ' ' << y << ' ' << j << endl;

        x = min(x, j);
        y = min(y, m - j - 1);

        if(x + y + 1 < m) {
            cout << "No" << endl;
            return 0;
        }
    } else {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
}