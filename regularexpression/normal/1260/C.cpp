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
    int T;
    cin >> T;
    while (T--) {
        int a, b, k;
        cin >> a >> b >> k;
        if (a == b) {
            cout << "OBEY\n";
            continue;
        }
        if (a > b) swap(a, b);
        int l = (b - 1) / a, r = (b - 1) % a;
        if (r == 0) {
            r = a;
            l--;
        }
        if (__gcd(a, b) <= r) {
            l++;
        }
        cout << (l >= k ? "REBEL\n" : "OBEY\n");
    }
    return 0;
}