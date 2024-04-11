#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    map <ll, ll> cnt;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int bal = 0;
        int mink = 0, maxk = 0;
        for (char c : s) {
            if (c == '(') {
                bal++;
            } else {
                bal--;
            }
            mink = min(mink, bal);
            maxk = max(maxk, bal);
        }
        //cout << s << " " << mink << " " << maxk << " " << bal << "\n";
        if (mink < 0 && mink == bal) {
            cnt[bal]++;
        }
        if (bal >= 0 && !mink) {
            cnt[bal]++;
        }
    }
    ll res = 0;
    for (auto p : cnt) {
        if (p.first > 0) break;
        if (!p.first) {
            res += p.second * p.second;
            continue;
        }
        //cout << p.first << " " << cnt[p.first] << " " << cnt[-p.first] << "\n";
        res += cnt[p.first] * cnt[-p.first];
    }
    cout << res;
}