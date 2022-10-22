#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    vector <int> data(MAXN, 0);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int k, k1;
        cin >> k;
        k1 = k;
        int newk = 0, pow1 = 1, x1 = x;
        for (int j = 0; j < 20; j++) {
            if (x % 2) {
                if (!(k % 2)) {
                    newk += pow1;
                }
            } else {
                if (k % 2) {
                    newk += pow1;
                }
            }
            pow1 *= 2;
            x /= 2;
            k /= 2;
        }
        x = x1;
        ans += data[newk];
        //cout << newk << endl;
        data[k1]++;
    }
    cout << ans;
}