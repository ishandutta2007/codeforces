#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int good[300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    ll ans = 0, cnt = 0;
    string s;
    cin >> n >> k >> s;
    s += '*';
    while(k--) {
        char c;
        cin >> c;
        good[c] = 1;
    }
    for(auto c : s) {
        if(good[c])
            cnt++;
        else {
            ans += cnt*(cnt + 1)/2;
            cnt = 0;
        }
    }
    cout << ans << '\n';
}