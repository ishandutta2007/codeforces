#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;

ll n, x1, y1, x2, y2, ans;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> n;
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        ans += (x2 - x1 + 1) * (y2 - y1 + 1);
    }

    cout << ans;


    return 0;
}