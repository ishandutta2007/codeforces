#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, u, v;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
        a.push_back(0);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u-1]++;
        a[v-1]++;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}