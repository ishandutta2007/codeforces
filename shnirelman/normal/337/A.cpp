#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

int main() {
    int n, m;
    cin >> m >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 1e9;
    for(int i = 0; i  + m<= n; i++)
        ans = min(ans, a[i + m - 1] - a[i]);

    cout << ans;


}