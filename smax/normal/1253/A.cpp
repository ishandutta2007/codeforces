#include <bits/stdc++.h>
using namespace std;

int a[100000], b[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];

        bool pushStart = false, pushed = false, solExists = true;
        for (int i=0; i<n; i++) {
            cin >> b[i];
            if (b[i] < a[i])
                solExists = false;
            else if (b[i] > a[i]) {
                if (pushed || i > 0 && b[i] - a[i] != b[i-1] - a[i-1] && a[i-1] != b[i-1])
                    solExists = false;
                pushStart = true;
            } else if (pushStart) {
                pushStart = false;
                pushed = true;
            }
        }

        cout << (solExists ? "YES" : "NO") << "\n";
    }

    return 0;
}