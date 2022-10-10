#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    int l = 0, r = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'L')
            l++;
        else
            r++;
    }

    cout << l + r + 1 << "\n";

    return 0;
}