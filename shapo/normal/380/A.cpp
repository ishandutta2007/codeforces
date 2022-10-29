#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define maxn 100500

typedef long long ll;

int val[maxn];
ll all_size;
vector < ll > end;
vector < int > type, mark;
int m, n;

int
main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin >> m;
    all_size = 0LL;
    end.push_back(0LL);
    type.push_back(0);
    mark.push_back(0);
    for (int i = 0; i < m; ++i) {
        int tp;
        int x, l, c;
        cin >> tp;
        type.push_back(tp);
        if (tp == 1) {
            cin >> x;
            ++all_size;
            if (all_size < maxn) {
                val[all_size] = x;
            }
            mark.push_back(x);
        } else {
            cin >> l >> c;
            int tmp = min(ll(maxn), all_size);
            for (int it = 0; tmp < maxn - 1 && it < c; ++it) {
                for (int it1 = 1; it1 <= l && tmp < maxn - 1; ++it1) {
                    val[++tmp] = val[it1];
                }
            }
            all_size = all_size + ll(l) * c;
            mark.push_back(l);
        }
        end.push_back(all_size);
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll cur_pos = 0LL;
        cin >> cur_pos;
        int pos = lower_bound(end.begin(), end.end(), cur_pos) - end.begin();
        if (type[pos] == 1) {
            cout << mark[pos] << " ";
        } else {
            int cur_l = mark[pos];
            ll pos_diff = cur_pos - end[pos - 1];
            pos_diff %= cur_l;
            if (pos_diff == 0) pos_diff = cur_l;
            cout << val[pos_diff] << " ";
        }
    }
    return 0;
}