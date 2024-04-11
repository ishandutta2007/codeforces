#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;
const int MAGIC = 500;
int sum[MAGIC + 5][MAGIC + 5], arr[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            arr[x] += y;
            for(ll d = 1; d <= MAGIC; d++)
                sum[d][x % d] += y;
        }
        else {
            if(x <= MAGIC)
                cout << sum[x][y] << '\n';
            else {
                int res = 0;
                for(int k = y; k <= 500000; k += x)
                    res += arr[k];
                cout << res << '\n';
            }
        }
    }
}