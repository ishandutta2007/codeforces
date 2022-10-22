#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int maxl = 0;
    int maxli;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > maxl) {
            maxl = a[i];
            maxli = i;
        }
    }
    int minr = 1000;
    int minri;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] < minr) {
            minr = a[i];
            minri = i;
        }
    }
    if (minri < maxli) {
        cout << maxli + n - minri - 2 << '\n';
    } else {
        cout << maxli + n - minri - 1 << '\n';
    }

    return 0;
}