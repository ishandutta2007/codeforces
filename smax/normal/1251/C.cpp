#include <bits/stdc++.h>
using namespace std;

bool visited[300000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;

        memset(visited, false, sizeof(visited));
        int i = 0, curParity = -1;
        for (int j=0; j<a.length(); j++) {
            if (curParity != -1 && a[j] % 2 != curParity) {
                while (a[i] < a[j]) {
                    if (!visited[i]) {
                        visited[i] = true;
                        cout << a[i];
                    }
                    i++;
                }
                if (i == j)
                    curParity = a[i] % 2;
                else {
                    visited[j] = true;
                    cout << a[j];
                }
            } else
                curParity = a[j] % 2;
        }
        while (i < a.length()) {
            if (!visited[i])
                cout << a[i];
            i++;
        }
        cout << "\n";
    }

    return 0;
}