#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s, t[2];
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        t[i%2] += s[i];
    if(t[1].empty())
        t[1] = "0";
    cout << (stoi(t[0]) + 1) * (stoi(t[1]) + 1) - 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}