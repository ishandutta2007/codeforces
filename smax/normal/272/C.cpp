#include <bits/stdc++.h>
using namespace std;

int a[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    int m;
    long long pre = 0;
    cin >> m;
    for (int i=0; i<m; i++) {
        int w, h;
        cin >> w >> h;

        long long mx = max((long long) a[w-1], pre);
        cout << mx << "\n";
        pre = max(pre, mx + h);
    }

    return 0;
}