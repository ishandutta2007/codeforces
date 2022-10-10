#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 1000;
const ll INF = 2e18;

ll h[MAX];
ll k[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll p, q;
    cin >> p >> q;
    int n;
    cin >> n;
    h[0] = 1;
    h[1] = 0;
    k[0] = 0;
    k[1] = 1;

    for(int i = 2; i < n + 2; i++) {
        ll a;
        cin >> a;
        if(h[i - 1] > 0 && a > INF / h[i - 1]) {
            cout << "NO\n";
            return 0;
        }
        if(k[i - 1] > 0 && a > INF / k[i - 1]) {
            cout << "NO\n";
            return 0;
        }
        h[i] = a*h[i - 1] + h[i - 2];
        k[i] = a*k[i - 1] + k[i - 2];
    }

    //for(int i = 0; i < n + 2; i++) {
    //    cout << h[i] << " " << k[i] << endl;
    //}

    ll g = __gcd(p, q);
    p /= g;
    q /= g;
    g = __gcd(h[n + 1], k[n + 1]);
    h[n + 1] /= g;
    k[n + 1] /= g;
    //cout << p << " " << q << " " << h[n + 1] << " " << k[n + 1] << endl;
    cout << ((k[n + 1] == p && h[n + 1] == q) ? "YES" : "NO") << '\n';
}