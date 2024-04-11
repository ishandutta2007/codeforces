#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> o(m, vector<int>(5, 0));
    string s;
    for (int qq = 0; qq < n; qq++) {
        cin >> s;
        for (int i = 0; i < m; i++) {
            o[i][s[i]-'A']++;
        }
    }
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    int ans = 0;
    int maxx;
    for (int i = 0; i < m; i++) {
        maxx = 0;
        for (int j = 0; j < 5; j++)
            maxx = max(maxx, o[i][j]);
        ans += maxx * a[i];
    }
    cout << ans << endl;
    return 0;
}