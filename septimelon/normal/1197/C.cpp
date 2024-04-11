#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> d(n-1);
    cin >> a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        d[i-1] = a[i] - a[i-1];
    }
    int delta;
    delta = a[n-1] - a[0];
    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());
    for (int i = 0; i < k-1; i++)
        delta -= d[i];
    cout << delta << endl;
    return 0;
}