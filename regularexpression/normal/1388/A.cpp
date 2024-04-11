#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

#define int long long
#define ll long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 30) cout << "NO\n"; else {
            int k = n - 6 - 10 - 14;
            if (k == 6 || k == 10 || k == 14) {
                if (n == 36) cout << "YES\n5 6 10 15\n";
                if (n == 40) cout << "YES\n5 6 14 15\n";
                if (n == 44) cout << "YES\n6 7 10 21\n";
            } else {
                cout << "YES\n6 10 14 " << k << '\n';
            }
        }
    }
    return 0;
}