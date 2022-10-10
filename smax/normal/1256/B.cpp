#include <bits/stdc++.h>
using namespace std;

int a[100];
bool op[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];

        memset(op, false, sizeof(op));
        int swaps = n - 1, i = n - 1, priority = 1;
        while (swaps > 0 && priority < n) {
            if (a[i] == priority && !op[i] && a[i-1] > a[i]) {
                swap(a[i-1], a[i]);
                swaps--;
                op[i] = true;
            }
            i--;
            if (i == priority - 1) {
                i = n - 1;
                priority++;
            }
        }

        for (int i=0; i<n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }

    return 0;
}