#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll n, m, k, num, ps, ans;
ll a[N], p[N];

void check(int x, int y, int x1, int y1, int x2, int y2) {
    if ((x >= x1 + x2 || y >= y1 + y2) && max(x1, x2) <= x && max(y1, y2) <= y) {
        cout << "YES\n";
        exit(0);
    }
}

int main() {
	// freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    check(x, y, x1, y1, x2, y2);
    check(x, y, x1, y1, y2, x2);
    check(x, y, y1, x1, x2, y2);
    check(x, y, y1, x1, y2, x2);
    cout << "NO\n";
    //return 0;
}