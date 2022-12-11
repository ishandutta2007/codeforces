#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

vector <int> a[N], ek[N];
vector <pair<int, int> > v, es[N];

ll c = 2e9;
ll x = 1, y = 1e9, res;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> x >> y;
    if (x * y == 1) {
        cout << 0;
        return 0;
    }
    while (true) {
        if (x == 0 || y == 0)
            break;
        res++;
        if (x < y) {
            x++;
            y -= 2;
        } else {
            y++;
            x -= 2;
        }
    }
    cout << res;



    return 0;
}