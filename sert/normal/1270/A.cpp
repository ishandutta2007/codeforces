#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<int> a(s1);
    vector<int> b(s2);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    cout << (*max_element(all(a)) > *max_element(all(b)) ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--) solve();
}