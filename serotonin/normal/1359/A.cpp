#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int x = min(n / k, m);
        int r = m - x, w = k - 1;
        int y = (r + w - 1) / w;
        printf("%d\n", x - y);
    }
}