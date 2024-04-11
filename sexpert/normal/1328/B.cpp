#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    k--;
    int uwu = 0;
    while(k >= uwu + 1) {
        k -= (uwu + 1);
        uwu++;
    }
    string s;
    for(int i = 0; i < n; i++)
        s += 'a';
    s[s.size() - uwu - 2] = 'b';
    s[s.size() - k - 1] = 'b';
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}