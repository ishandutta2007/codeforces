#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500;

int n, k;
string s;


int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    /*for (int i = 0; i < 50; i++)
        for (int j = 0; j < 40; j++)
            cout << 50 + i << " " << 40 + j << "\n";
    return 0;*/

    cin >> n >> k >> s;
    if (k <= n / 2) {
        for (int i = 1; i < k; i++) printf("LEFT\n");
        for (int i = 0; i < n; i++) {
            printf("PRINT %c\n", s[i]);
            if (i + 1 < n)
                printf("RIGHT\n");
        }
    } else {
        for (int i = k; i < n; i++) printf("RIGHT\n");
        for (int i = n - 1; i >= 0; i--) {
            printf("PRINT %c\n", s[i]);
            if (i > 0)
                printf("LEFT\n");
        }
    }

    return 0;
}