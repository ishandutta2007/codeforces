#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int a[300000];
    cin >> n;
    int k = 1100000000;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) k = min(k, a[i]/i);
        if (i < n-1) k = min(k, a[i]/(n-i-1));
    }
    if (k == 1100000000) k = 0;
    cout << k << endl;
    return 0;
}