#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
int a[MAXN], b[MAXN], nines[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
        a[i + 1] = s[i] - '0';
    for(int i = 1; i <= k; i++)
        b[i] = a[i];
    for(int i = k + 1; i <= n; i++)
        b[i] = b[i - k];
    int p;
    for(p = k + 1; p <= n; p++) {
        if(b[p] > a[p]) {
            p = n + 1;
            break;
        }
        if(a[p] > b[p])
            break;
    }
    if(p == n + 1) {
        cout << n << '\n';
        for(int i = 1; i <= n; i++)
            cout << b[i];
        cout << '\n';
        return 0;
    }
    for(p = k; p >= 1; p--) {
        if(b[p] != 9)
            break;
    }
    for(int i = p; i <= n; i += k)
        b[i]++;
    for(int q = p + 1; q <= k; q++)
        for(int i = q; i <= n; i += k)
            b[i] = 0;
    cout << n << '\n';
    for(int i = 1; i <= n; i++)
        cout << b[i];
    cout << '\n';
}