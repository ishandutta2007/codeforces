#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define len(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()

void solve() {
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    cout << (a + b >= n + m && min(a, b) >= m ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}