#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++) {
        bool f = false;
        for(int j = max(0, i - x); j < i; j++)
            f = (f || (a[i] > a[j]));

        for(int j = i + 1; j <= min(i + y, n - 1); j++) {
            f = (f || (a[i] > a[j]));
            //cout << i << ' ' << a[j] << endl;
        }


        if(!f) {
            cout << i + 1;
            return 0;
        }
    }
}