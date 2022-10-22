#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int K = 9;
const int M = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0;
    for(char c : s)
        cnt += c - '0';

    if(cnt % 2 == 1 || cnt == 0) {
        cout << "NO\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            int u = i;
            vector<pii> ans;
            for(int j = 1; j < n; j++) {
                int v = (i + j) % n;
//                cout << "for " << i << ' ' << " u = " << u << "   v = " << v << endl;
//                cout << "ans : " << endl;
//                for(auto p : ans)
//                    cout << p.f + 1 << ' ' << p.s + 1 << '\n';
//                cout << endl;
                if(u != -1) {
                    ans.emplace_back(u, v);
                    if(s[v] == '0')
                        u = v;
                    else
                        u = -1;
                } else {
                    int x = ans.back().f, y = ans.back().s;
                    ans.pop_back();
                    if((x - i + n) % n < (y - i + n) % n)
                        swap(x, y);
                    ans.emplace_back(x, v);
                    ans.emplace_back(y, v);
                    if(s[v] == '0')
                        u = -1;
                    else
                        u = v;
                }
            }
            cout << "YES\n";
            for(auto p : ans)
                cout << p.f + 1 << ' ' << p.s + 1 << '\n';
            return;
        }

    }

//    int v = (s[0] == '0' ? 0 : -1), u = 0;
//    vector<pii> ans;
//    for(int i = 1; i < n; i++) {
//        if(s[i] == '0') {
//            if(v == -1) {
//                ans.emplace_back(u, i);
//                u = i;
//            } else {
//                ans.emplace_back(u, i);
//                u = v;
//                v = -1;
//            }
//        } else {
//            if(v == -1) {
//                v = u;
//                u = i;
//            } else {
//                ans.emplace_back(u, i);
////                v = i;
//                u = v;
//            }
//        }
//    }
//
//    if(v != -1)
//        ans.emplace_back(v, u);
//
//    cout << "YES\n";
//    for(auto p : ans)
//        cout << p.f + 1 << ' ' << p.s + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}