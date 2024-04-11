#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int cnt[256];
    memset(cnt, 0, sizeof cnt);
    string s;
    cin >> s;
    for(auto c : s)
        cnt[c]++;
    int nv = min(cnt['U'], cnt['D']), nh = min(cnt['L'], cnt['R']);
    if(nh + nv == 0) {
        cout << "0\n";
        return;
    }
    if(nh == 0) {
        cout << "2\n";
        cout << "UD\n";
        return;
    }
    if(nv == 0) {
        cout << "2\n";
        cout << "LR\n";
        return;
    }
    cout << 2*(nh + nv) << '\n';
    for(int i = 0; i < nh; i++) cout << 'R';
    for(int i = 0; i < nv; i++) cout << 'U';
    for(int i = 0; i < nh; i++) cout << 'L';
    for(int i = 0; i < nv; i++) cout << 'D';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}