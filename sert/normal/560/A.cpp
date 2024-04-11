#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;

ll n, x;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) {
            cout << "-1";
            return 0;
        }
    }

    cout << 1;

    return 0;
}