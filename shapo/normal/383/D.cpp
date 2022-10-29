#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef vector < int > vi;
typedef vector < vi > v2i;
typedef long long ll;
const ll MD = 1000000007;


/*
 * returns sum in range[l, r]
 */
int
get_sum(int l, int r, vi &part_sum)
{
    if (!l) {
        return part_sum[r];
    }
    return part_sum[r] - part_sum[l - 1];
}

void
add(int &dst, int src)
{
    dst += src;
    if (dst >= MD) {
        dst -= MD;
    }
}

/*
 * computing answer for all segments [left; right] in [l; r)
 * @param a vector of elements
 * @param part_sum vector of partial_sums 
 */
void
compute(int l, int r, vi &a, vi &part_sum, v2i &left_d, v2i &right_d, ll &ans)
{
    if (l == r - 1) {
        fill(left_d[l].begin(), left_d[l].end(), 0);
        left_d[l][0] = 1;
        left_d[l][a[l]] = 1;
        right_d[l] = left_d[l];
        return;
    }
    int mid = (l + r) / 2;
    compute(l, mid, a, part_sum, left_d, right_d, ans);
    compute(mid, r, a, part_sum, left_d, right_d, ans);
    vi positive_cnt(part_sum.back() + 1, 0);
    vi negative_cnt(positive_cnt);
    for (int right_bord = mid; right_bord < r; ++right_bord) {
        int all_s = get_sum(mid, right_bord, part_sum);
        for (int j = 0; j <= all_s; ++j) {
            if (all_s - 2 * j < 0) {
                add(negative_cnt[2 * j - all_s], left_d[right_bord][j]);
            } else {
                add(positive_cnt[all_s - 2 * j], left_d[right_bord][j]);
            }
        }
    }
    for (int left_bord = l; left_bord < mid; ++left_bord) {
        int all_s = get_sum(left_bord, mid - 1, part_sum);
        for (int j = 0; j <= all_s; ++j) {
            if (2 * j - all_s < 0) {
                ans = (ans + ll(negative_cnt[all_s - 2 * j]) * right_d[left_bord][j]) % MD;
            } else {
                ans = (ans + ll(positive_cnt[2 * j - all_s]) * right_d[left_bord][j]) % MD;
            }
        }
    }
    vi tmp_add = right_d[mid];
    int tmp_add_size = int(tmp_add.size());
    for (int i = mid - 1; i >= l; --i) {
        int cur = a[i];
        for (int j = tmp_add_size - 1; j >= cur; --j) {
            add(tmp_add[j], tmp_add[j - cur]);
        }
        right_d[i] = tmp_add;
    }
    tmp_add = left_d[mid - 1];
    tmp_add_size = int(tmp_add.size());
    for (int i = mid; i < r; ++i) {
        int cur = a[i];
        for (int j = tmp_add_size - 1; j >= cur; --j) {
            add(tmp_add[j], tmp_add[j - cur]);
        }
        left_d[i] = tmp_add;
    }
}

int
main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vi part_sum(n, 0);
    partial_sum(a.begin(), a.end(), part_sum.begin());
    int upper_half = 5000;
    v2i left_cnt(n, vi(upper_half + 1, 0));
    v2i right_cnt(left_cnt);
    ll res = 0LL;
    compute(0, n, a, part_sum, left_cnt, right_cnt, res);
    cout << res << '\n';
    return 0;
}