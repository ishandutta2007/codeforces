#include <bits/stdc++.h>

using namespace std;

const int INF = 1e4;
const int MAXN1 = 907;
const int MAXN2 = 8107;
int main() {
    int n;
    cin >> n;
    int now = 2, prev = 1;
    n--;
    while (true) {
        if (n < now) {
            cout << prev << endl;
            for (int i = 1; i < prev; i++) {
                cout << i << " ";
            }
            cout << prev + n;
            return 0;
        }
        n -= now;
        prev++;
        now++;
    }
}