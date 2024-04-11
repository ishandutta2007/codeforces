#include <bits/stdc++.h>
using namespace std;

string s[20], t[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> s[i];
    for (int i=0; i<m; i++)
        cin >> t[i];

    int q;
    cin >> q;
    while (q--) {
        int y;
        cin >> y;

        int i = y % n, j = y % m;
        cout << s[(i+n-1)%n] + t[(j+m-1)%m] << "\n";
    }

    return 0;
}