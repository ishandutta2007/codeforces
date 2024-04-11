#include <bits/stdc++.h>
using namespace std;
int t, n, w, a[15], num[11];
char s[15];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    num[1] = 1;
    for(int i=2; i<=10; ++i) num[i] = num[i-1] * 10;
    cin >> t;
    while (t--) {
        cin >> n >> w;
        int p = 0, cnt = 0;
        for(int i=n; i; i/=10) p += a[++cnt] = i % 10;
        while (p < w) {
            for(int i=2; i<=cnt; ++i) if (a[i]) {
                a[i] -= 1;
                a[i-1] += 10;
                p += 9;
                break;
            }
        }
        for(int i=1; i<=cnt; ++i) {
            while (w > 1 && a[i] > 0) --w, --a[i], n -= num[i], cout << num[i] << ' ';
        }
        cout << n << '\n';
    }
}