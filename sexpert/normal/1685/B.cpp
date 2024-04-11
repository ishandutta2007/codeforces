#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    // A B AB BA
    int a, b, c, d;
    cin >> a >> b >> c >> d >> s;
    int ca = a + c + d;
    for(auto &x : s)
        ca -= (x == 'A');
    if(ca != 0) {
        cout << "NO\n";
        return;
    }
    string t;
    vector<int> to_ab, to_ba;
    int tot = 0;
    s += s.back();
    for(int i = 0; i < s.size(); i++) {
        if(i >= 1 && s[i - 1] == s[i]) {
            tot += (t.size() - 1)/2;
            //cout << t << '\n';
            if(t.size() % 2 == 0) {
                int x = t.size() / 2;
                if(t[0] == 'A')
                    to_ab.push_back(x);
                else
                    to_ba.push_back(x);
            }
            t.clear();
        }
        t += s[i];
    }

    //cout << tot << '\n';

    int cur = 0;
    sort(to_ab.begin(), to_ab.end());
    int p = 0;
    while(p < to_ab.size()) {
        if(cur + to_ab[p] <= c) {
            cur += to_ab[p];
            p++;
            tot++;
        }
        else
            break;
    }

    cur = 0;
    sort(to_ba.begin(), to_ba.end());
    p = 0;
    while(p < to_ba.size()) {
        if(cur + to_ba[p] <= d) {
            cur += to_ba[p];
            p++;
            tot++;
        }
        else
            break;
    }

    cout << (tot >= c + d ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}