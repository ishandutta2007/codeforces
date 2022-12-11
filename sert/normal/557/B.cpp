#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 7;

ll n, a[N];
ll o1, o2, w;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> w;
    w *= 2;
    for (int i = 0; i < n * 2; i++)
    	cin >> a[i];
    sort(a, a + n + n);

    o1 = a[0] * n * 6;
    o2 = a[n] * n * 3;

    w = min(w, min(o1, o2));

    cout << w / 2 << "." << w % 2 * 5 << "\n";

    return 0;
}