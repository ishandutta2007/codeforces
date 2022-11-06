#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        int f = a[0] - '0';
        vector<int> p;
        for (int i = n - 1; i >= 0; --i) {
            int x = ((n - i) & 1) ? n - (n - i) / 2 - 1 : (n - i) / 2;
            int y = a[x] - '0';
            if (!((n - i) & 1)) {
                y ^= 1;
            }
            int z = b[i] - '0';
            if (f == z) {
                p.push_back(0);
            }
            p.push_back(i);
            f = y ^ 1;
        }
        cout << p.size();
        for (int x : p) {
            cout << " " << x + 1;
        }
        cout << '\n';
    }
    return 0;
}