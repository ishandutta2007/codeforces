#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<string> subs[30];
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        int m = s.size();
        for(int i = 0; i < m; i++) {
            for(int sz = 1; i + sz <= m; sz++) {
                subs[sz].insert(s.substr(i, sz));
                //cout << s.substr(i, sz) << '\n';
            }
        }
    }
    string ans;
    for(int len = 1; len <= 5; len++) {
        int cnt = 1;
        for(int j = 0; j < len; j++)
            cnt *= 26;
        if(subs[len].size() == cnt)
            continue;
        for(int k = 0;;k++) {
            string fk;
            int x = k;
            for(int i = 0; i < len; i++) {
                fk += (char)('a' + (x % 26));
                x /= 26;
            }
            reverse(fk.begin(), fk.end());
            if(subs[len].count(fk))
                continue;
            cout << fk << '\n';
            return 0;
        }
    }
}