#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define pa pair
#define tu tuple

typedef uint32_t uint;
typedef int64_t ll;

typedef ve<int> vi;
typedef ve<vi> v2i;
typedef pa<int, int> pii;

int
main()
{
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vi a(n);
    vi cnt(2, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < q; ++i) {
        int t, p;
        cin >> t >> p;
        if (t == 1) {
            p--;
            cnt[a[p]]--;
            a[p] ^= 1;
            cnt[a[p]]++;
        } else {
            int res = cnt[1] >= p ? 1 : 0;
            cout << res << '\n';
        }
    }
    return 0;
}