#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a;
    int n;
    cin >> n;
    int buf;
    for (int i = 0; i < n; i++) {
        cin >> buf;
        a.push_back(buf);
    }
    sort(a.begin(), a.end());
    if (a[n-1] >= a[n-2] + a[n-3]) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    cout << a[n-2] << " " << a[n-1];
    for (int i = 3; i <= n; i++) {
        cout << " " << a[n-i];
    }
    return 0;
}