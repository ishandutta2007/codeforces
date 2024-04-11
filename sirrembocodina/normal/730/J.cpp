#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int a[110], b[110], tmp[110];
int d[110][110][11000];

int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        tmp[i] = -b[i];
    }
    sort(tmp, tmp + n);
    int k = n, cur = sum;
    for (int i = 0; i < n; ++i) {
        cur += tmp[i];
        if (cur <= 0) {
            k = i + 1;
            break;
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int v = 0; v < 11000; ++v) {
                d[i][j][v] = -1000000000;
            }
        }
    }
    d[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int v = 0; v <= 10000; ++v) {
                if (j < k) {
                    d[i + 1][j + 1][v + b[i]] = max(d[i + 1][j + 1][v + b[i]], d[i][j][v] + a[i]);
                }
                d[i + 1][j][v] = max(d[i + 1][j][v], d[i][j][v]);
            }
        }
    }
    int mx = 0;
    for (int v = sum; v <= 10000; ++v) {
        mx = max(mx, d[n][k][v]);
    }
    cout << k << " " << sum - mx << endl;
    return 0;
}