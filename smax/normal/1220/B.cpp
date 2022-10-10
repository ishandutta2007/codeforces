#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, a[1000][1000];
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];

    int x = sqrt((long long) a[0][1] * a[0][2] / a[1][2]);
    cout << x << " ";
    for (int i=1; i<n; i++)
        cout << a[0][i] / x << " ";

    return 0;
}