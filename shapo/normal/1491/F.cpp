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
get_range(int x, int a, int b) {
    // Adjust indices from range [0; n) to range [1; n]
    x += 1;
    a += 1;
    b += 1;
    int l = 1, r = b - a;
    cout << "? " << l << " " << r << endl;
    cout << x << endl;
    cout << a;
    for (int i = a + 1; i < b; ++i) {
        cout << ' ' << i;
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void
solve()
{
    int n;
    cin >> n;
    vector<char> empty(n, 1);
    int i = 1;
    while (get_range(i, 0, i) == 0) ++i;
    // a[i] != 0, second element in queue
    empty[i] = 0;
    for (int j = i + 1; j < n; ++j) {
        if (get_range(i, j, j + 1) != 0) {
            empty[j] = 0;
        }
    }
    // Use at most (n - 1) request
    // Left with at least 1 + [log_2 n] requests
    // to found one number in segment [0; i)
    // Use binary search
    int l = 0; // no number in [0; l)
    int r = i; // number in [0; r)
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (get_range(i, 0, m) == 0) {
            l = m;
        } else {
            r = m;
        }
    }
    empty[r - 1] = 0;
    vi ans;
    for (int i = 0; i < n; ++i) {
        if (empty[i]) ans.push_back(i);
    }
    cout << "! " << ans.size();
    for (int x : ans) {
        cout << ' ' << x + 1;
    }
    cout << endl;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}