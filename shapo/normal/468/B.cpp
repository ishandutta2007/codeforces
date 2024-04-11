#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;

template< class T >
void
output_arr(const T &arr, int cnt, bool yes = true)
{
    if (yes) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    for (int i = 0; yes && i < cnt; ++i) {
        cout << arr[i] << ' ';
    }
    if (yes) {
        cout << "\n";
    }
}

int n;
int a, b;
vector< int > p;
vector< int > col;
vector< int > used;
vector< pair< int, int > > all_vals;

void
dfs(int x, vector< int > &lp)
{
    used[x] = 1;
    for (auto sub : {a, b}) {
        auto it = lower_bound(all_vals.begin(), all_vals.end(), make_pair(sub - p[x], 0));
        if (it != all_vals.end() && it->first == sub - p[x]) {
            int to = it->second;
            if (!used[to]) {
                dfs(to, lp);
            }
        }
    }
    lp.push_back(x);
}

bool
check(int sub, const vector< int > &arr)
{
    for (auto x : arr) {
        auto it = lower_bound(all_vals.begin(), all_vals.end(), make_pair(sub - p[x], 0));
        if (it == all_vals.end() || it->first != sub - p[x]) {
            return false;
        }
    }
    return true;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    all_vals.resize(n);
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        all_vals[i].first = p[i];
        all_vals[i].second = i;
    }
    sort(all_vals.begin(), all_vals.end());
    col.assign(n, 0);
    used.assign(n, 0);
    bool ok = true;
    for (int i = 0; ok && i < n; ++i) {
        if (!used[i]) {
            vector< int > all_n;
            dfs(i, all_n);
            if (!check(a, all_n)) {
                ok = check(b, all_n);
                for (auto x : all_n) {
                    col[x] = 1;
                }
            }
        }
    }
    output_arr(col, n, ok);
    return 0;
}