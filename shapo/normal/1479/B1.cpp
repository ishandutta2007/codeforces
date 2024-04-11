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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ve<vi> stack_occ(n + 1, vi(1, n));
    for (int i = n - 1; i >= 0; --i) {
        stack_occ[a[i]].push_back(i);
    }
    vi segs = {0, 0};
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int idx = (stack_occ[segs[0]].back() < stack_occ[segs[1]].back()) ? 0 : 1;
        if (segs[0] == a[i]) {
            idx = 1;
        } else if (segs[1] == a[i]) {
            idx = 0;
        }
        if (segs[idx] != a[i]) ++res;
        segs[idx] = a[i];
        stack_occ[a[i]].pop_back();
    }
    cout << res << '\n';
    return 0;
}