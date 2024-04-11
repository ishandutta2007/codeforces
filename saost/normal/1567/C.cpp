#include <bits/stdc++.h>
using namespace std;
int t, n, res, a[15], b[15], num[20];
char s[15];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    for(int i=0; i<10; ++i) num[i] = i + 1;
    for(int i=10; i<20; ++i) num[i] = 19 - i;
    cin >> t;
    while (t--) {
        cin >> s;
        n = strlen(s);
        for(int i=0; i<n; ++i) a[i] = s[n - i - 1] - '0';
        for(int i=0; i*4<(1<<n); ++i) {
            for(int j=0; j<n; ++j) b[j] = a[j];
            for(int j=0; j<n; ++j) {
                if ((i>>j)&1) b[j] += 10, b[j+2] -= 1;
            }
            int ans = 1;
            for(int j=0; j<n; ++j) {
                ans *= num[b[j]];
            }
            res += ans;
        }
        cout << res - 2 << '\n';
        res = 0;
    }
}