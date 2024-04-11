#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

//const bool debug_out = false;
const bool debug_out = true;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 30;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;
const ld eps = 1e-15;

/*
*/

void solve() {
    int n;
    cin >> n;

    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<string, int> mp;
    set<string> st;
    set<string> used;
    for(int i = 0; i < n; i++) {
//        cout << i << endl;
        mp[a[i]]++;
        string b = a[i];
        reverse(b.begin(), b.end());
        if(mp[b]) {
            cout << "YES" << endl;
            return;
        }

//        for(auto p : mp) {
//            cout << p.f << ' ' << p.s << endl;
//        }

        if(a[i].size() == 3) {
            mp[a[i].substr(0, 2)]++;
            {
                string s = a[i].substr(1, 2);
                reverse(s.begin(), s.end());
//                cout << "sagdf " << s << ' ' <<
                if(st.count(s)) {
//                    cout << "sfasrg" << endl;
                    cout << "YES" << endl;
                    return;
                }
            }

            char c;
            if(a[i][0] == a[i][1])
                c = a[i][2];
            else if(a[i][1] == a[i][2])
                c = a[i][0];
            else
                continue;

            string s = "";
            s += c;
            if(mp.count(s)) {
                cout << "YES" << endl;
                return;
            }
        } else  {
            for(auto s : st) {
                string t = s + a[i];
                if(t.size() <= 3)
                    mp[t]++;
                else
                    mp[t.substr(0, 3)]++;
            }
            st.insert(a[i]);
        }
    }

    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}