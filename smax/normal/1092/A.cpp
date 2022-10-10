#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int di = n / k, rm = n % k;
        char c = 'a';
        for (int i=0; i<k; i++) {
            for (int j=0; j<di+(rm>0); j++)
                cout << c;
            c++;
            rm--;
        }
        cout << "\n";
    }

    return 0;
}