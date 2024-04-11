#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

void move(ll& x, ll& y, int dx, int dy, ll r, ll &n) {
    ll step = min(r, n);
    x += dx * step, y += dy * step;
    n -= step;
}

int main() {
    cin >> n;
    if(n == 0) return !printf("0 0");
    ll l = 0, r = (ll)1.5e9, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(3 * mid * (mid + 1) < n) l = mid;
        else r = mid;
    }
    ll x = 2 * l + 2, y = 0;
    n -= 3 * l * (l + 1);
    int dic[6][2] = {{-1, 2}, {-2, 0}, {-1, -2}, {1, -2}, {2, 0}, {1, 2}};
    int cur = 0;
    while(n > 0) {
        move(x, y, dic[cur][0], dic[cur][1], r, n);
        cur ++;
    }
    cout << x << " " << y << endl;
}