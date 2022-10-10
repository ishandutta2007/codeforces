#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;

        int l = 0, r = 0, u = 0, d = 0;
        for (char c : s) {
            if (c == 'L') l++;
            else if (c == 'R') r++;
            else if (c == 'U') u++;
            else d++;
        }

        int minLR = min(l, r), minUD = min(u, d);
        if (minLR == 0 && minUD > 0)
            minUD = 1;
        else if (minUD == 0 && minLR > 0)
            minLR = 1;

        cout << 2 * minLR + 2 * minUD << "\n";
        for (int i=0; i<minLR; i++)
            cout << 'L';
        for (int i=0; i<minUD; i++)
            cout << 'U';
        for (int i=0; i<minLR; i++)
            cout << 'R';
        for (int i=0; i<minUD; i++)
            cout << 'D';
        cout << "\n";
    }

    return 0;
}