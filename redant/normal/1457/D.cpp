#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;
int a[MX];
int n;

int solve() {
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int xs = 0;
            for (int j = 0; j < len; j++)
                xs ^= a[i+j];
            int x = 0;
            for (int j = 0; j + 1 < len; j++) {
                x ^= a[i+j];
                if (x > (x ^ xs))
                    return len - 2;
            }
        }
    }
    return -1;
}

int main() {
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve() << "\n";
    return 0;
}