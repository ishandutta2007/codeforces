#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 2e6 + 34;
const long double EPS = 1e-12;
const int INF = 1e9 + 34;
const int md = 1e8;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

ll n, nn, m;
vector <ll> v;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    nn = n;
    if (n == 1) {
        cout << "1\n0\n";
        return 0;
    }

    for (ll i = 2; i * i <= nn; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i * i == nn) {
                cout << "2\n";
                return 0;
            }
            if (nn % (i * i) == 0) {
                cout << "1\n" << i * i;
                return 0;
            }
            n /= i;
        }
    }
    if (n > 1)
        v.push_back(n);

    if (v.size() == 1) {
        cout << "1\n0\n";
        return 0;
    } 
    ll m = v[0] * v[1];
    if (m == nn) {
        cout << "2\n";
    } else {
        cout << "1\n" << m;
    }

    return 0;
}