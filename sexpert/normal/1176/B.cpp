#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void test_case() {
    int c[3], ans = 0;
    c[0] = c[1] = c[2] = 0;
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        c[x % 3]++;
    }
    ans = c[0];
    int d = min(c[1], c[2]);
    c[1] -= d;
    c[2] -= d;
    ans += d;
    cout << ans + c[1]/3 + c[2]/3 << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while(t--)
        test_case();
}