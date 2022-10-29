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
typedef pa<ll, ll> pll;

bool
good_angle(const pll& a, const pll& b, const pll& c)
{
    // check angle <ABC is acute
    pll ba{a.first - b.first, a.second - b.second};
    pll bc{c.first - b.first, c.second - b.second};
    ll dp = ba.first * bc.first + ba.second * bc.second;
    return dp > 0ll;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    ve<pll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    vi ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = i;
    }
    for (int i = 2; i < n; ++i) {
        // sift x_i down
        int pos = i;
        while (pos >= 2
               && !good_angle(p[ans[pos - 2]], p[ans[pos - 1]], p[ans[pos]])) {
            swap(ans[pos], ans[pos - 1]);
            pos--;
        }
    }
    for (int x : ans) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
    return 0;
}