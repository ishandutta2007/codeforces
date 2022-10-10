#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; 2*i + 1 < n; i++)
        ans += a[2*i + 1] - a[2*i];
    cout << ans << endl;
}