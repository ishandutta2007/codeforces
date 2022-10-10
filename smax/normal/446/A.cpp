#include <bits/stdc++.h>
using namespace std;

int a[100000], l[100000], r[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    int ret = 1;
    l[0] = 1;
    for (int i=1; i<n; i++) {
        l[i] = (a[i] > a[i-1] ? l[i-1] : 0) + 1;
        ret = max(ret, l[i-1] + 1);
    }

    r[n-1] = 1;
    for (int i=n-2; i>=0; i--) {
        r[i] = (a[i] < a[i+1] ? r[i+1] : 0) + 1;
        ret = max(ret, r[i+1] + 1);
    }

    for (int i=1; i<n-1; i++)
        if (a[i+1] > a[i-1] + 1)
            ret = max(ret, l[i-1] + r[i+1] + 1);

    cout << ret << "\n";

    return 0;
}