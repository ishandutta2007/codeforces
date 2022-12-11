#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 2e6 + 34;
const long double EPS = 1e-12;
const int INF = 1e9 + 34;
const int md = 1e8;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int n, x, xx, y, ans;
int a[N];
vector <int> v;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    while (n --> 0) {
        cin >> x;
        xx = x;
        y = 1;
        v.clear();
        for (int j = 2; j * j <= xx; j++) 
            if (x % j == 0) {
                y = max(y, 1 + a[j]);
                v.push_back(j);
                while (x % j == 0)
                    x /= j;
            }
        if (x > 1) {
            y = max(y, 1 + a[x]);
            v.push_back(x);
        }
        ans = max(ans, y);
        for (int i = 0; i < v.size(); i++)
            a[v[i]] = max(a[v[i]], y);
    }

    // for (int i = 0; i < 11; i++)
    //     cout << a[i] << " "; cout << "\n";

    cout << ans;

    return 0;
}