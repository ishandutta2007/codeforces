#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

ll n, a[1000];
char c[1000], d[1000];

int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = 'L';
        d[i] = 'R';
        if (i == 0)
            swap(c[i], d[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            if (j != 0) {
                cout << c[i] << d[i];
            }
            cout << "P";
        }
        if (i != n - 1)
            cout << "R";
    }

    return 0;
}