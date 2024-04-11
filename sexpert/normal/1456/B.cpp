#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1e5 + 10;
int pxor[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pxor[i] = pxor[i - 1] ^ x;
    }

    if(n >= 70) {
        cout << "1\n";
        return 0;
    }

    int ans = 200;
    for(int a = 0; a <= n; a++) {
        for(int b = a + 1; b <= n; b++) {
            for(int c = b + 1; c <= n; c++) {
                if((pxor[b] ^ pxor[a]) > (pxor[c] ^ pxor[b])) {
                    ans = min(ans, c - a - 2);
                }
            }
        }
    }

    cout << (ans == 200 ? -1 : ans) << '\n';
}