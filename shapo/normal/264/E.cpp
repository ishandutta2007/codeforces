#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>

#ifdef _DEBUG
#include <cassert>
#define ensure(expr) assert(expr)
#else
#define ensure(expr) (void)(true || expr)
#endif

using namespace std;

const int MAXN = 100500;
const int MAXM = 300500;
const int MAXK = 131072;

int n, m;
int tp[MAXM], p[MAXM], h[MAXM];
int cnt[2 * MAXK];
int tree_x[2 * MAXK], tree_y[2 * MAXK];
int curk;

int
getPos(int sum)
{
    int v = 1;
    for (; v < curk; ) {
        v *= 2;
        if (sum - cnt[v] > 0) {
            sum -= cnt[v++];
        }
    }
    return v - curk + 1;
}

void
updSum(int x, int add_val, int *tree)
{
    x += curk - 1;
    do {
        tree[x] += add_val;
        x /= 2;
    } while (x);
}

void
updMax(int x, int new_val, int *tree)
{
    x += curk - 1;
    tree[x] = new_val;
    while (x != 1) {
        x /= 2;
        tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
    }
}

int
getMax(int l, int r, int *tree)
{
    int res = 0;
    l += curk - 1;
    r += curk - 1;
    while (l < r) {
        res = max(res, max(tree[l], tree[r]));
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r) {
        res = max(res, tree[l]);
    }
    return res;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> tp[i] >> p[i];
        if (tp[i] == 1) {
            cin>> h[i];
            h[i] -= i - 1;
        }
    }
    {
        // assigning from h -> [1..cnt_unique]
        vector< int > all_vals;
        all_vals.reserve(m);
        for (int i = 1; i <= m; ++i) {
            if (tp[i] == 1) {
                all_vals.push_back(h[i]);
            }
        }
        sort(all_vals.begin(), all_vals.end());
        all_vals.resize(unique(all_vals.begin(), all_vals.end()) - all_vals.begin());
        for (int i = 1; i <= m; ++i) {
            if (tp[i] == 1) {
                h[i] = lower_bound(all_vals.begin(), all_vals.end(), h[i]) - all_vals.begin() + 1;
            }
        }
    }
    // init trees
    curk = 2;
    while (curk < n) {
        curk *= 2;
    }
    set< pair< int, int > > x_vals, y_vals;
    for (int i = 1; i <= m; ++i) {
        if (tp[i] == 1) {
            //cerr << "1 " << p[i] << " " << h[i] << endl;
            int cur_pos = p[i], cur_h = h[i];
            updSum(cur_pos, 1, cnt);
            vector< pair< int, int > > tmp_ids;
            tmp_ids.reserve(16);
            while (!y_vals.empty()) {
                pair< int, int > tmp = *(y_vals.begin());
                ensure(tmp.first != cur_h);
                if (tmp.first >= cur_h) {
                    break;
                }
                //cerr << "delete (" << tmp.second << ", " << tmp.first << ")" << endl;
                updMax(tmp.second, 0, tree_x);
                updMax(tmp.first, 0, tree_y);
                tmp_ids.push_back(make_pair(tmp.first, tmp.second));
                y_vals.erase(tmp);
            }
            tmp_ids.push_back(make_pair(cur_h, cur_pos));
            x_vals.insert(make_pair(cur_pos, cur_h));
            for (vector< pair< int, int > >::const_reverse_iterator it = tmp_ids.rbegin(); 
                    it != tmp_ids.rend(); ++it) {
                int len = getMax(it->second + 1, curk, tree_x);
                //cerr << "for (" << it->second << ", " << it->first << ") ans is " << len + 1 << endl;
                updMax(it->second, len + 1, tree_x);
                updMax(it->first, len + 1, tree_y);
                y_vals.insert(*it);
            }
        } else {
            int cur_pos = getPos(p[i]);
            //cerr << "2 " << p[i] << " -> " << cur_pos << endl;
            updSum(cur_pos, -1, cnt);
            vector< pair< int, int > > tmp_ids;
            tmp_ids.reserve(16);
            while (!x_vals.empty()) {
                pair< int, int > tmp = *(x_vals.begin());
                if (tmp.first > cur_pos) {
                    break;
                }
                updMax(tmp.first, 0, tree_x);
                updMax(tmp.second, 0, tree_y);
                tmp_ids.push_back(make_pair(tmp.first, tmp.second));
                x_vals.erase(tmp);
            }
            ensure(tmp_ids.back().first == cur_pos);
            int cur_h = tmp_ids.back().second;
            y_vals.erase(make_pair(cur_h, cur_pos));
            tmp_ids.pop_back();
            for (vector< pair< int, int > >::const_reverse_iterator it = tmp_ids.rbegin(); 
                    it != tmp_ids.rend(); ++it) {
                int len = getMax(it->second + 1, curk, tree_y);
                updMax(it->first, len + 1, tree_x);
                updMax(it->second, len + 1, tree_y);
                x_vals.insert(*it);
            }
        }
        ensure(getMax(1, curk, tree_x) == getMax(1, curk, tree_y));
        cout << getMax(1, curk, tree_x) << '\n';
    }
    return 0;
}