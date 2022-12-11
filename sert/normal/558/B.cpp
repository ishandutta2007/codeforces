#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 7;

ll n, a[N], f[N], l[N], ans, p = -1, k[N];

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < N; i++)
    	f[i] = -1;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (f[a[i]] == -1)
    		f[a[i]] = i;
    	l[a[i]] = i;
    	k[a[i]]++;
    }
    for (int i = 0; i < N; i++)
    	ans = max(ans, k[i]);
    for (int i = 0; i < N; i++)
    	if (k[i] == ans && (l[i] - f[i] < l[p] - f[p] || p == -1))
			p = i;
	cout << f[p] + 1 << " " << l[p] + 1<< "\n";

    return 0;
}