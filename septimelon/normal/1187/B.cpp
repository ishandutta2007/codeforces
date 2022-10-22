#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;
    int n, m;
    int maxin[26];
    vector<pair<int,int>> fre[26];
    cin >> n >> s >> m;
    vector<int> ans(m, 0);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 26; j++)
            fre[j].push_back(pair<int,int>(0,i));
    for (int i = 0; i < m; i++) {
        cin >> t;
        for (int q = 0; q < t.size(); q++)
            fre[t[q]-'a'][i].first++;
    }
    for (int i = 0; i < 26; i++) {
        sort(fre[i].begin(), fre[i].end());
        reverse(fre[i].begin(), fre[i].end());
        maxin[i] = fre[i][0].first;
    }
    /*for (int i = 0; i < m; i++)
        cout << fre[0][i].first << " ";
    cout << endl;*/
    int wa;
    for (int i = 0; i < n; i++) {
        wa = s[i]-'a';
        if (maxin[wa] == 0) continue;
        maxin[wa]--;
        for (int q = 0; q < m && fre[wa][q].first > 0; q++) {
            fre[wa][q].first--;
            if (fre[wa][q].first == 0)
                ans[fre[wa][q].second] = i+1;
        }
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << endl;
    return 0;
}