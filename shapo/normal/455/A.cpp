#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 100500;

ll ans[MAXN];
int cnt[MAXN];

int
main()
{
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < MAXN; ++i) {
        cnt[i] = 0;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        cnt[cur]++;
    }
    ans[0] = 0LL;
    for (int i = 1; i < MAXN; ++i) {
        ans[i] = ans[i - 1];
        if (i == 1) {
            ans[i] = max(ans[i], 1ll * cnt[i] * i);
        } else {
            ans[i] = max(ans[i], ans[i - 2] + 1ll * cnt[i] * i);
        }
    }
    cout << ans[MAXN - 1] << '\n';
    return 0;
}