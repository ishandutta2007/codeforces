#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int main() {
    int n;
    cin >> n;
    int maxk = 1;
    vector <int> data(n, 0), cnt(MAXN, 0);
    for (int j = 0; j < n; j++) {
        int x;
        cin >> x;
        int k = sqrt(x);
        for (int i = 2; i <= k; i++) {
            if (x % i == 0) {
                cnt[i]++;
                while (x % i == 0) x /= i;
                maxk = max(maxk, cnt[i]);
            }
        }
        if (x != 1) {
            cnt[x]++;
            maxk = max(maxk, cnt[x]);
        }
    }
    cout << maxk;
}