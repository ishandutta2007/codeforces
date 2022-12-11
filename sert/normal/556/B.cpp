#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;

ll n, x, k;

void fail() {
    cout << "No";
    exit(0);
}

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n;
    cin >> x;
    x = (n - x) % n;
    for (int i = 1; i < n; i++) {
        cin >> k;
        if (i % 2) {
            if ((k + n - x) % n != i) fail();
        } else {
            if ((k + x) % n != i) fail();
        }
    }

    cout << "Yes";
    return 0;
}