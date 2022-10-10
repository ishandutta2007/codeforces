#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int ans = 100;
        for(int inc = 0; inc < 40; inc++) {
            int c = b + inc;
            if(c == 1)
                continue;
            int op = 0, x = a;
            while(x) {
                op++;
                x /= c;
            }
            ans = min(ans, inc + op);
        }
        cout << ans << '\n';
    }
}