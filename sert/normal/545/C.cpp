#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 7;

ll n, x[N], h[N], lst, ans = 2;
ll d[N][2];

int main() {
	 // freopen("a.in", "r", stdin);
	 // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> h[i];

    d[0][0] = d[0][1] = 1;

    for (int i = 1; i < n; i++) {
        d[i][0] = d[i - 1][0];
        if (x[i] - h[i] > x[i - 1])
            d[i][0]++;
        if (x[i] - h[i] > x[i - 1] + h[i - 1])
            d[i][0] = max(d[i][0], d[i - 1][1] + 1);
        if (x[i - 1] + h[i - 1] < x[i])
            d[i][0] = max(d[i][0], d[i - 1][1]);
        d[i][1] = d[i - 1][0] + 1;
        if (x[i - 1] + h[i - 1] < x[i])
            d[i][1] = max(d[i][1], d[i - 1][1] + 1);
        //cout << d[i][0] << " " << d[i][1] << "\n";
    }

    cout << max(d[n - 1][0], d[n - 1][1]);
    
    //return 0;
}