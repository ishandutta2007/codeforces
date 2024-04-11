#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string n;
    cin >> n;

    for (int i=0; i<n.length(); i++) {
        if (n[i] == '0' || n[i] == '8') {
            cout << "YES\n" << n[i] << "\n";
            return 0;
        }
        for (int j=i+1; j<n.length(); j++) {
            if ((10 * (n[i] - '0') + n[j] - '0') % 8 == 0) {
                cout << "YES\n" << 10 * (n[i] - '0') + n[j] - '0' << "\n";
                return 0;
            }
            for (int k=j+1; k<n.length(); k++)
                if ((100 * (n[i] - '0') + 10 * (n[j] - '0') + n[k] - '0') % 8 == 0) {
                    cout << "YES\n" << 100 * (n[i] - '0') + 10 * (n[j] - '0') + n[k] - '0' << "\n";
                    return 0;
                }
        }
    }
    cout << "NO\n";

    return 0;
}