#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll a[30][30], d, n;
string s, t;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> s >> t;

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            a[i][j] = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            a[s[i] - 'a'][t[i] - 'a'] = i + 1;
            d++;
        }
    }

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (a[i][j] != -1 && a[j][i] != -1) {
                cout << d - 2 << "\n";
                cout << a[i][j] << " " << a[j][i] << "\n";
                return 0;
            }

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            for (int k = 0; k < 26; k++)
                if (a[i][j] != -1 && a[j][k] != -1) {
                    cout << d - 1 << "\n";
                    cout << a[i][j] << " " << a[j][k] << "\n";
                    return 0;
                }

    cout << d << "\n";
    cout << "-1 -1\n";




    //return 0;
}