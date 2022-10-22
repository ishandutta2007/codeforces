#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        long long c;
        cin >> c;
        if (c < 15) {
            cout << "NO" << endl;
        } else if (c % 14 < 7 && c % 14 > 0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}