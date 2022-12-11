#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
ll n, m, t, k, ans;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            k++;
    cout << abs(n - 2 * k);

    return 0;
}