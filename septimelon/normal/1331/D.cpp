#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    if ((s[6] - '0') % 2 == 1) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
    return 0;
}