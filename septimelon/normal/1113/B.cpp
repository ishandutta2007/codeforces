#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1) {
        cout << a[0];
        return 0;
    }
    sort (a.rbegin(), a.rend());
    //cout << a[0] << endl;
    int sum0;
    int divm = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 1; i <= a[k]; i++) {
            if (a[k] % i == 0) {
                sum0 = a[k] + a[n-1] - a[k] / i - a[n-1] * i;
                if (divm < sum0){
                    //cout << divm << "; " << a[k] << ", " << a[n-k] << " in " << i << endl;
                    divm = sum0;
                }
            }
        }
    }
    sum0 = 0;
    for (int i = 0; i < n; i++)
        sum0 += a[i];
    sum0 -= divm;
    cout << sum0;
    return 0;
}