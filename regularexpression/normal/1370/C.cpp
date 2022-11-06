#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define ll long long
#define ld long double

bool pr(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    if (n == 1) cout << "FastestFinger\n"; else {
        if ((n & 1) || n == 2) cout << "Ashishgup\n"; else {
            int c = 0;
            while (n % 2 == 0) {
                n /= 2;
                c++;
            }
            if (n == 1) cout << "FastestFinger\n"; else cout << (c >= 2 || !pr(n) ? "Ashishgup\n" : "FastestFinger\n");
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}