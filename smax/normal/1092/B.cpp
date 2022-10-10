#include <bits/stdc++.h>
using namespace std;

int a[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a + n);
    int ret = 0;
    for (int i=0; i<n; i+=2)
        ret += a[i+1] - a[i];

    cout << ret << "\n";

    return 0;
}