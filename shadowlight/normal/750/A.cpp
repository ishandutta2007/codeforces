#include <bits/stdc++.h>

using namespace std;

vector <int> str;

bool fl = 0;

int MAXN = 25000;

int main() {
    int n, k;
    cin >> n >> k;
    k = 240 - k;
    for (int i = 1; i <= n; i++) {
        if (k < 5 * i) {
            cout << i - 1;
            return 0;
        }
        k -= 5 * i;
    }
    cout << n << endl;
 }