#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll n, sum, ans, a[N];
char t[N];
bool u[N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	while (a[i] % 2 == 0)
    		a[i] /= 2;
    	while (a[i] % 3 == 0)
    		a[i] /= 3;
    }
    sort(a, a + n);
    cout << (a[0] == a[n - 1] ? "YES" : "NO");
}