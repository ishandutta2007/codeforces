#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <map>
#include <string>
using namespace std;
const int N = 1e5 + 34;
int n, k, la, lb;
int a[N], b[N];
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n >> k;
    if (k == 0) {
        for (int i = 0; i < n * 2; i++)
            cout << i + 1 << " ";
        return 0;
    }
    cout << k + 1 << " 1 ";
    for (int i = 1; i < n * 2; i++)
        if (i != k)
            b[lb++] = i;
    for (int i = 0; i < n - 1; i++)
        cout << b[i] + 1 << " " << b[lb - i - 1] + 1 << " ";
    return 0;
}