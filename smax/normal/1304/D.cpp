#include <bits/stdc++.h>
using namespace std;

int ret[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        for (int i=0; i<n; i++)
            ret[i] = n - i;
        for (int i=0; i<n; i++) {
            int j = i;
            while (j < n - 1 && s[j] == '<')
                j++;
            reverse(ret + i, ret + j + 1);
            i = j;
        }
        for (int i=0; i<n; i++)
            cout << ret[i] << " ";
        cout << "\n";

        for (int i=0; i<n; i++)
            ret[i] = i + 1;
        for (int i=0; i<n; i++) {
            int j = i;
            while (j < n - 1 && s[j] == '>')
                j++;
            reverse(ret + i, ret + j + 1);
            i = j;
        }
        for (int i=0; i<n; i++)
            cout << ret[i] << " ";
        cout << "\n";
    }

    return 0;
}