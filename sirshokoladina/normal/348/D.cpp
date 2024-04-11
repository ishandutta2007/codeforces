#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)

typedef long long ll;

const ll mod = 1000000007;

string s;

ll a[2][3010], b[2][3010];

int main () {
    int n, m;
    cin >> n >> m;
    getline(cin, s);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    forn (i, n) {
        getline(cin, s);
        forn (j, m) {
            (a[(i + 1) & 1][j + 1] = a[i & 1][j + 1] + a[(i + 1) & 1][j]) %= mod;
            (b[(i + 1) & 1][j + 1] = b[i & 1][j + 1] + b[(i + 1) & 1][j]) %= mod;
            if (i == 0 && j == 1) {
                a[(i + 1) & 1][j + 1] = 1;
            }
            if (i == 1 && j == 0) {
                b[(i + 1) & 1][j + 1] = 1;
            }
            if (s[j] == '#') {
                a[(i + 1) & 1][j + 1] = b[(i + 1) & 1][j + 1] = 0;
            }
        }
    }
    cout << ((
        a[(n - 1) & 1][m] * b[n & 1][m - 1] - 
        b[(n - 1) & 1][m] * a[n & 1][m - 1]
    ) % mod + mod) % mod << endl;
}