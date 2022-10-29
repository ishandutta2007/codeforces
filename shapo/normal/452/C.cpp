#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

int
main()
{
    int n, m;
    cin >> n >> m;
    cout << fixed << setprecision(15);
    if (n * m == 1) {
        cout << 1.;
    } else {
        cout << (1. / n + (n - 1.) / n * (m - 1.) / (m * n - 1.));
    }
    cout << '\n';
    return 0;
}