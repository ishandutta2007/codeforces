#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 5e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

void solve() {
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());

    vector<int> cnt(3, 0);
    for(int i = 0; i < s.size(); i++) if(s[i] <= 'c') {
        cnt[s[i] - 'a']++;
    }

    if(min({cnt[0], cnt[1], cnt[2]}) == 0) {
//        sort(s.begin(), s.end());
        cout << s << endl;
    } else {
        for(int i = 0; i < cnt[0]; i++)
            cout << 'a';
        if(t == "abc") {
            for(int i = 0; i < cnt[2]; i++)
                cout << 'c';
            for(int i = 0; i < cnt[1]; i++)
                cout << 'b';

        } else {
            for(int i = 0; i < cnt[1]; i++)
                cout << 'b';
            for(int i = 0; i < cnt[2]; i++)
                cout << 'c';
        }

        for(int i = 0; i < s.size(); i++) if(s[i] > 'c')
            cout << s[i];
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}