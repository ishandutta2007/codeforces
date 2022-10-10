#include <bits/stdc++.h>
using namespace std;

int a[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];

        sort(a, a + n, greater<int>());
        int ret = 0;
        while (ret < n && a[ret] > ret)
            ret++;

        cout << ret << "\n";
    }

    return 0;
}