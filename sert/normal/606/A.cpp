#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100][100], b;
int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < 3; i++)
            cin >> a[i][j];
    for (int i = 0; i < 3; i++) {
        if (a[i][0] > a[i][1])
            b += (a[i][0] - a[i][1]) / 2;
        else
            b += a[i][0] - a[i][1];
    }
    cout << (b >= 0 ? "Yes" : "No");


    return 0;
}