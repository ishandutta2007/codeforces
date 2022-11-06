#include<bits/stdc++.h>
using namespace std;
 
#define x first
#define y second
#define pb push_back
#define mp make_pair
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
 
#define ll long long
#define int long long
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, x;
        cin >> n >> x >> a >> b;
        cout << min(n - 1, abs(a - b) + x) << '\n';
    }
    return 0;
}