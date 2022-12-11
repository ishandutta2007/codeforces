#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
ll MX = (1ll << 32ll) - 1;
void solve() {
    int n;
    vector<ll> a = {1};
    ll sum = 0;
    cin >> n;
    string s;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        if (s[0] == 'a') {
            sum += a.back();
            if (sum > MX) {
                cout << "OVERFLOW!!!\n";
                return;
            }
        }
        if (s[0] == 'e') {
            a.pop_back();
        }
        if (s[0] == 'f') {
            int value;
            sscanf(s.substr(4).c_str(), "%d", &value);
            a.push_back(min(MX + 1, a.back() * value));
        }
    }
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 3;
    for (int i = 1; i < T; i++) solve();    
#endif
}