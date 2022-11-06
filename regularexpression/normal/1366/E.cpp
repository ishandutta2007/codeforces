#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

#define ll long long

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = n-2; i >= 0; i--) a[i] = min(a[i], a[i+1]);
    map<int, int> ma;
    for (auto e : a) ma[e]++;
    int ans = a[0] == b[0];
    for (int i = 1; i < m; i++) ans = (ll)ans * ma[b[i]] % mod;
    cout << ans;
    return 0;
}