#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 200005;
int t, n, k, cnt, ansl, ansr, bit[N], old[N];
long long a[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for(int i=1; i<=n; ++i) cin >> a[i], a[i] = -a[i] + a[i - 1];

        ansl = 2; ansr = 0;
        for(int i=1, j=0; i<=n; ++i) {
            while (a[i] - a[j] > k) ++j;
            if (i - j > ansr - ansl) {
                ansl = j;
                ansr = i;
            }
        }
        if (ansl + 1 > ansr) cout << -1 << '\n';
        else cout << ansl + 1 << ' ' << ansr << '\n';
    }
}