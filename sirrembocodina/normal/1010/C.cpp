#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int a[100100];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int res = k;
    forn (i, n) {
        cin >> a[i];
        a[i] %= k;
        res = gcd(a[i], res);
    }
    cout << k / res << endl;
    forn (i, k / res) {
        cout << res * i << ' ';
    }
    cout << endl;
    return 0;
}