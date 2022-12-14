#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll n, k;

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> n >> k;
    if (k > (n * n + 1) / 2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (k > 0 && (i + j) % 2 == 0) {
                k--;
                cout << "L";
            } else 
                cout << "S";
        }
        cout << "\n";
    }

    //return 0;
}