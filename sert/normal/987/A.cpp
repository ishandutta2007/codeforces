#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    map<string, string> mp;
    mp["purple"] = "Power";
    mp["green"] = "Time";
    mp["blue"] = "Space";
    mp["orange"] = "Soul";
    mp["red"] = "Reality";
    mp["yellow"] = "Mind";

    set<string> s = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
    int n;
    cin >> n;
    while (n--) {
        string st;
        cin >> st;
        s.erase(mp[st]);
    }
    cout << s.size() << "\n";
    for (string ss : s) cout << ss << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 2;
    for (int i = 1; i < T; i++) solve();    
#endif
}