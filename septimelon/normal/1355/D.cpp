#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, s;
    cin >> n >> s;
    if (n * 2 > s) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n - 1; ++i) {
        cout << "2 ";
    }
    cout << s - 2 * (n - 1) << "\n";
    cout << "1\n";
    return 0;
}