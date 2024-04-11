#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    string a;
    cin >> n >> k >> a;

    int incPos = k - 1;
    while (incPos >= 0 && a[incPos] == '9')
        incPos--;
    if (incPos >= 0) {
        bool change = false;
        for (int i=k; i<n; i++) {
            if (a[i] > a[i%k]) {
                change = true;
                break;
            } else if (a[i] < a[i%k])
                break;
        }
        if (change) {
            a[incPos]++;
            for (int i=incPos+1; i<k; i++)
                a[i] = '0';
        }
    }

    cout << n << "\n";
    for (int i=0; i<n; i++) {
        if (i >= k)
            a[i] = a[i-k];
        cout << a[i];
    }
    cout << "\n";

    return 0;
}