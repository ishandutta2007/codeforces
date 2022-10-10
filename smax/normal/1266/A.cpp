#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;

        int sum = 0;
        bool hasZero = false, hasEven = false;
        for (char c : s) {
            sum += c - '0';
            if (c == '0' && !hasZero)
                hasZero = true;
            else if (c % 2 == 0)
                hasEven = true;
        }

        if (sum % 3 == 0 && hasZero && hasEven)
            cout << "red\n";
        else
            cout << "cyan\n";
    }

    return 0;
}