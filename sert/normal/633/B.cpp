#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 34;
int n, x;
int main() {
    cin >> n;
    int k = 0;
    for (int i = 5; true; i += 5) {
        x = i;
        while (x % 5 == 0) {
            x /= 5;
            k++;
        }
        if (k > n) {
            cout << 0;
            return 0;
        }
        if (k == n) {
            cout << "5\n";
            for (int j = 0; j < 5; j++)
                cout << i + j << " ";
            return 0;
        }
    }
}