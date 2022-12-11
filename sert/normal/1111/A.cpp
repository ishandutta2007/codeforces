#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

string kek(string s) {
    string res;
    string aa = "aouie";
    for (char ch: s) {
        res += (aa.find(ch) == string::npos ? "pum" : "pam");
    }
    return res;
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (kek(s1) == kek(s2) ? "Yes\n" : "No\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 4;
    for (int i = 1; i < T; i++) solve();    
#endif
}