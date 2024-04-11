#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ld st(ld a, int step) {
    if (step == 0) return 1.0;
    if (step % 2 == 0) {
        ld q = st(a, step / 2);
        return q * q;
    }
    return a * st(a, step - 1);
}

int n, m;
ld p[N], sum;

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        p[i] = st((i + 0.0) / (m + 0.0), n);
        p[i] -= p[i - 1];
        sum += p[i] * i;
        p[i] += p[i - 1];
    }
    
    cout.precision(10);
    cout << fixed << sum;
    //return 0;
}