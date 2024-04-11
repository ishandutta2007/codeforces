#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

int v1, v2, t, d, ans;
int v[N];

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> v1 >> v2 >> t >> d;
    v[1] = v1;
    v[t] = v2;
    for (int i = 2; i < t; i++) {
        v[i] = min(v[i - 1] + d, (t - i) * d + v2);
    }
    for (int i = 1; i <= t; i++)
        ans += v[i];
    cout << ans;
    //return 0;
}