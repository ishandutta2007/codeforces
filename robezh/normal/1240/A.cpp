#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;

int n;
int p[N];
ll psum[N];
ll x, a, y, b;
ll k;

ll getsum(int a, int b) {
    return psum[b] - (a == 0 ? 0 : psum[a - 1]);
}

bool check(int mid) {
    int share = (mid + 1) / (a * b / __gcd(a, b));
    int ca = (mid + 1) / a - share, cb = (mid + 1) / b - share;
    ll sum = getsum(0, share - 1) / 100 * (x + y) + getsum(share, share + ca - 1) / 100 * x + getsum(share + ca, share + ca + cb - 1) / 100 * y;
    return sum >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> p[i];
        cin >> x >> a;
        cin >> y >> b;
        if(x < y) {
            swap(x, y);
            swap(a, b);
        }
        cin >> k;
        sort(p, p + n, greater<>());
        psum[0] = p[0];
        for(int i = 1; i < n; i++) psum[i] = psum[i-1] + p[i];
        int l = -1, r = n, mid;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        if(r == n) cout << "-1" << "\n";
        else cout << r + 1 << "\n";
    }
}