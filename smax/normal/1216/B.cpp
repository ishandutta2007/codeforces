#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    pair<int, int> a[1000];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a, a + n, greater<pair<int, int>>());
    int ret = 0;
    for (int i=0; i<n; i++)
        ret += a[i].first * i + 1;

    cout << ret << "\n";
    for (int i=0; i<n; i++)
        cout << a[i].second << " ";
    cout << "\n";

    return 0;
}