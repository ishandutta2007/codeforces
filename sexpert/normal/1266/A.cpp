#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[300];

void solve() {
    string s;
    cin >> s;
    memset(cnt, 0, sizeof cnt);
    if(s == "0") {
        cout << "red\n";
        return;
    }
    for(auto c : s)
        cnt[c]++;
    if(cnt['0'] == 0) {
        cout << "cyan\n";
        return;
    }
    cnt['0']--;
    int sum = 0, ce = 0;
    for(int i = '0'; i <= '9'; i++) {
        sum += (i - '0') * cnt[i];
        if(cnt[i] > 0 && (i - '0') % 2 == 0)
            ce++;
    }
    if(sum % 3 == 0 && ce > 0) {
        cout << "red\n";
        return;
    }
    cout << "cyan\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}