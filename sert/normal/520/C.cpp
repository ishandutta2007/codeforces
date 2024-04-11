#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 2011;
const ll md = 1e9 + 7;

string s, t = "ACGT";
ll k, mx, n, ans;
ll a[N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        a[s[i] - 'A']++;
    }
    mx = -1;
    for (int i = 0; i < 4; i++) mx = max(mx, a[t[i] - 'A']);
    for (int i = 0; i < 4; i++) 
        if (mx == a[t[i] - 'A'])
            k++;

    ans = 1;
    for (int i = 0; i < n; i++)
        ans = (ans * k) % md;

    cout << ans;

    //return 0;
}