#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (m >= n && k >= n) {
        cout << "Yes";
        return 0;
    }
    cout << "No" << endl;
    return 0;
}