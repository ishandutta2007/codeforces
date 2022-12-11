#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;

ll n;
char a[111][111];

int main() {
   // freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i + 1][j + 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (((a[i][j-1]=='o')+(a[i][j+1]=='o')+(a[i-1][j]=='o')+(a[i+1][j]=='o')) % 2 != 0) {
                cout << "NO\n";
                return 0;
            }

    cout << "YES\n";

    return 0;
}