#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void reduce(vector<vector<int>> &v) {
    int n = v.size();
    for(int i = 0; i < n; i++)
        for(int j = n - 1; j >= 0; j--)
            v[i][j] ^= v[i][0];

    for(int j = 1; j < n; j++)
        for(int i = n - 1; i >= 0; i--)
            v[i][j] ^= v[0][j];
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v1(n, vector<int>(n)), v2;
    v2 = v1;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
            v1[i][j] = (s[j] - '0');
    }
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
            v2[i][j] = (s[j] - '0');
    }
    reduce(v1);
    reduce(v2);
    cout << ((v1 == v2) ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}