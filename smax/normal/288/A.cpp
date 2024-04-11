#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    if (k > n || k == 1 && n > 1)
        cout << "-1\n";
    else if (k == 1 && n == 1)
        cout << "a\n";
    else {
        for (int i=0; i<n-k+2; i++)
            cout << (i % 2 == 0 ? 'a' : 'b');
        for (int i=0; i<k-2; i++)
            cout << (char) ('c' + i);
        cout << "\n";
    }

    return 0;
}