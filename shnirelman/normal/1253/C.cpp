#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0;  i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<li> s(n, 0);
    for(int i = 0; i < n; i++) {
        s[i] = a[i] + (i >= m ? s[i - m] : 0);
    }

    li ans = 0;
    for(int i = 0; i < n; i++) {
        ans += s[i];
        cout << ans << ' ';
    }
}