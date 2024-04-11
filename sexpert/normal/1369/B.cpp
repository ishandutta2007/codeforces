#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    string s, ini, fin;
    cin >> n >> s;
    while(s.back() == '1') {
        fin += '1';
        s.pop_back();
    }
    reverse(s.begin(), s.end());
    while(s.back() == '0') {
        ini += '0';
        s.pop_back();
    }
    if(s.empty())
        cout << ini << fin << '\n';
    else
        cout << ini << "0" << fin << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}