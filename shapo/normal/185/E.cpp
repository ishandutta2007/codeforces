#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <utility>
#include <tuple>
#include <numeric>

using namespace std;

typedef long long ll;

typedef pair< int, int > pii;

const int INF = 1000000000;

struct Point
{
    int x, y;
    Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    Point(std::istream &in)
    {
        in >> x >> y;
        x *= 2;
        y *= 2;
    }
};

bool
operator<(const Point &a, const Point &b)
{
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

bool
cmp_sum(const Point &a, const Point &b)
{
    return (a.x + a.y < b.x + b.y);
}

bool
cmp_diff(const Point &a, const Point &b)
{
    return (a.x - a.y < b.x - b.y);
}

int n, k;
vector< Point > gnome, metro;

vector< int > sorted_x, sorted_y;
vector< int > tree;
int curk;

void
upd_val(int x, int val, const vector< int > &coords)
{
    x = lower_bound(coords.begin(), coords.end(), x) - coords.begin();
    x += curk;
    tree[x] = min(tree[x], val);
    x /= 2;
    while (x != 1) {
        tree[x] = min(tree[x * 2], tree[x * 2 + 1]);
        x /= 2;
    }
}

int
get_min_val(int l, int r, const vector< int > &coords)
{
    l = lower_bound(coords.begin(), coords.end(), l) - coords.begin();
    r = lower_bound(coords.begin(), coords.end(), r) - coords.begin();
    l += curk;
    r += curk;
    int res = INF;
    while (l < r) {
        res = min(res, min(tree[l], tree[r]));
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r) {
        res = min(res, tree[l]);
    }
    return res;
}

void
shrink(vector< int > &coord)
{
    sort(coord.begin(), coord.end());
    coord.resize(unique(coord.begin(), coord.end()) - coord.begin());
}

template< typename T >
std::vector< int >
argsort(const std::vector< T > &vals, bool reverse = false)
{
    vector< int > result(vals.size());
    for (int i = 0; i < int(vals.size()); ++i) {
        result[i] = i;
    }
    sort(result.begin(), result.end(), [&](int a, int b) -> bool
                {return (vals[a] < vals[b]); });
    if (reverse) {
        std::reverse(result.begin(), result.end());
    }
    return result;
}

void
get_min_dist(
        const std::vector< Point > &gnome,
        std::vector< Point > metro,
        std::vector< int > &result)
{
    sorted_x.clear();
    sorted_y.clear();
    for (auto &x : gnome) {
        sorted_x.push_back(x.x);
        sorted_y.push_back(x.y);
    }
    for (auto &x : metro) {
        sorted_x.push_back(x.x);
        sorted_y.push_back(x.y);
    }
    shrink(sorted_x);
    shrink(sorted_y);
    int nn = gnome.size();
    result.assign(nn, INF);
    auto indices = argsort(gnome);
    sort(metro.begin(), metro.end());
    curk = 2;
    while (int(sorted_y.size()) > curk) curk *= 2;
    {   // bottom left
        tree.assign(2 * curk, INF);
        int l = 0, r = 0;
        while (l < nn) {
            int ind = indices[l];
            while (r < k && metro[r].x <= gnome[ind].x) {
                upd_val(metro[r].y, -metro[r].x - metro[r].y, sorted_y);
                ++r;
            }
            result[ind] = min(result[ind], get_min_val(sorted_y.front(), gnome[ind].y, sorted_y) 
                    + gnome[ind].x + gnome[ind].y);
            ++l;
        }
    }
    { // top left
        tree.assign(2 * curk, INF);
        int l = 0, r = 0;
        while (l < nn) {
            int ind = indices[l];
            while (r < k && metro[r].x <= gnome[ind].x) {
                upd_val(metro[r].y, -metro[r].x + metro[r].y, sorted_y);
                ++r;
            }
            result[ind] = min(result[ind], get_min_val(gnome[ind].y, sorted_y.back(), sorted_y) 
                    + gnome[ind].x - gnome[ind].y);
            ++l;
        }
    }
    reverse(metro.begin(), metro.end());
    reverse(indices.begin(), indices.end());
    { // bottom right
        tree.assign(2 * curk, INF);
        int l = 0, r = 0;
        while (l < nn) {
            int ind = indices[l];
            while (r < k && metro[r].x >= gnome[ind].x) {
                upd_val(metro[r].y, metro[r].x - metro[r].y, sorted_y);
                ++r;
            }
            result[ind] = min(result[ind], get_min_val(sorted_y.front(), gnome[ind].y, sorted_y) 
                    - gnome[ind].x + gnome[ind].y);
            ++l;
        }
    }
    { // top right
        tree.assign(2 * curk, INF);
        int l = 0, r = 0;
        while (l < nn) {
            int ind = indices[l];
            while (r < k && metro[r].x >= gnome[ind].x) {
                upd_val(metro[r].y, metro[r].x + metro[r].y, sorted_y);
                ++r;
            }
            result[ind] = min(result[ind], get_min_val(gnome[ind].y, sorted_y.back(), sorted_y) 
                    - gnome[ind].x - gnome[ind].y);
            ++l;
        }
    }
}

int
find_dist(pair< pii, pii > rect, const Point &pnt)
{
    int sum = pnt.x + pnt.y;
    int diff = pnt.x - pnt.y;
    int sum_dist = max(0, -min(rect.first.second, sum) + max(rect.first.first, sum));
    int diff_dist = max(0, -min(rect.second.second, diff) + max(rect.second.first, diff));
    return max(sum_dist, diff_dist);
}

void
get_all_min_dist(
        vector< pair< pii, pii > > rect,
        vector< Point > metro,
        vector< int > &dist)
{
    dist.assign(n, INF);
    vector< Point > ok_points;
    for (int i = 0; i < n; ++i) {
        const auto &cr = rect[i];
        int a, b, c, d;
        tie(a, b) = cr.first;
        tie(c, d) = cr.second;
        ok_points.emplace_back((a + c) / 2, (a - c) / 2);
        ok_points.emplace_back((a + d) / 2, (a - d) / 2);
        ok_points.emplace_back((b + c) / 2, (b - c) / 2);
        ok_points.emplace_back((b + d) / 2, (b - d) / 2);
    }
    vector< int > tmp;
    get_min_dist(ok_points, metro, tmp);
    for (int i = 0; i < n * 4; ++i) {
        dist[i / 4] = min(dist[i / 4], tmp[i]);
    }
    vector< int > sorted_sum;
    vector< int > sorted_diff;
    for (auto &pnt : rect) {
        sorted_sum.push_back(pnt.first.first);
        sorted_sum.push_back(pnt.first.second);
        sorted_diff.push_back(pnt.second.first);
        sorted_diff.push_back(pnt.second.second);
    }
    for (auto &pnt : metro) {
        sorted_sum.push_back(pnt.x + pnt.y);
        sorted_diff.push_back(pnt.x - pnt.y);
    }
    shrink(sorted_sum);
    shrink(sorted_diff);
    sort(metro.begin(), metro.end(), cmp_sum);
    curk = 2;
    while (curk < int(sorted_diff.size())) curk *= 2;
    vector< pair< pii, pii > > segment(n);
    for (int i = 0; i < n; ++i) {
        segment[i] = make_pair(make_pair(rect[i].first.first, i), rect[i].second);
    }
    sort(segment.begin(), segment.end());
    {
        tree.assign(curk * 2, INF);
        int nn = segment.size();
        int l = 0, r = 0;
        while (l < nn) {
            while (r < k && metro[r].x + metro[r].y <= segment[l].first.first) {
                upd_val(metro[r].x - metro[r].y, -metro[r].y - metro[r].x, sorted_diff);
                ++r;
            }
            int ind = segment[l].first.second;
            dist[ind] = min(dist[ind], get_min_val(segment[l].second.first,
                        segment[l].second.second, sorted_diff) + segment[l].first.first);
            ++l;
        }
    }
    reverse(metro.begin(), metro.end());
    for (int i = 0; i < n; ++i) {
        segment[i] = make_pair(make_pair(rect[i].first.second, i), rect[i].second);
    }
    sort(segment.rbegin(), segment.rend());
    {
        tree.assign(curk * 2, INF);
        int nn = segment.size();
        int l = 0, r = 0;
        while (l < nn) {
            while (r < k && metro[r].x + metro[r].y >= segment[l].first.first) {
                upd_val(metro[r].x - metro[r].y, metro[r].x + metro[r].y, sorted_diff);
                ++r;
            }
            int ind = segment[l].first.second;
            dist[ind] = min(dist[ind], get_min_val(segment[l].second.first,
                        segment[l].second.second, sorted_diff) - segment[l].first.first);
            ++l;
        }
    }
    sort(metro.begin(), metro.end(), cmp_diff);
    for (int i = 0; i < n; ++i) {
        segment[i] = make_pair(make_pair(rect[i].second.first, i), rect[i].first);
    }
    sort(segment.begin(), segment.end());
    curk = 2;
    while (curk < int(sorted_sum.size())) curk *= 2;
    {
        tree.assign(curk * 2, INF);
        int nn = segment.size();
        int l = 0, r = 0;
        while (l < nn) {
            while (r < k && metro[r].x - metro[r].y <= segment[l].first.first) {
                upd_val(metro[r].x + metro[r].y, metro[r].y - metro[r].x, sorted_sum);
                ++r;
            }
            int ind = segment[l].first.second;
            dist[ind] = min(dist[ind], get_min_val(segment[l].second.first,
                        segment[l].second.second, sorted_sum) + segment[l].first.first);
            ++l;
        }
    }
    reverse(metro.begin(), metro.end());
    for (int i = 0; i < n; ++i) {
        segment[i] = make_pair(make_pair(rect[i].second.second, i), rect[i].first);
    }
    sort(segment.rbegin(), segment.rend());
    {
        tree.assign(curk * 2, INF);
        int nn = segment.size();
        int l = 0, r = 0;
        while (l < nn) {
            while (r < k && metro[r].x - metro[r].y >= segment[l].first.first) {
                upd_val(metro[r].x + metro[r].y, metro[r].x - metro[r].y, sorted_sum);
                ++r;
            }
            int ind = segment[l].first.second;
            dist[ind] = min(dist[ind], get_min_val(segment[l].second.first,
                        segment[l].second.second, sorted_sum) - segment[l].first.first);
            ++l;
        }
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        gnome.emplace_back(std::cin);
    }
    for (int i = 0; i < k; ++i) {
        metro.emplace_back(std::cin);
    }
    int min_x = INF, max_x = -INF;
    int min_y = INF, max_y = -INF;
    for (const auto &pnt : gnome) {
        min_x = min(min_x, pnt.x + pnt.y);
        max_x = max(max_x, pnt.x + pnt.y);
        min_y = min(min_y, pnt.x - pnt.y);
        max_y = max(max_y, pnt.x - pnt.y);
    }
    int result = (max(max_x - min_x, max_y - min_y) + 1) / 2;
    if (n > 1 && k) {
        vector< int > dist;
        get_min_dist(gnome, metro, dist);
        auto indices = argsort(dist, true);
        vector< pair< pii, pii > > all_rect;
        vector< int > add_dist;
        min_x = INF, max_x = -INF;
        min_y = INF, max_y = -INF;
        for (int i = 0; i < n; ++i) {
            const auto &pnt = gnome[indices[i]];
            min_x = min(min_x, pnt.x + pnt.y);
            max_x = max(max_x, pnt.x + pnt.y);
            min_y = min(min_y, pnt.x - pnt.y);
            max_y = max(max_y, pnt.x - pnt.y);
            int dist = (max(max_x - min_x, max_y - min_y) + 1) / 2;
            add_dist.push_back(dist);
            all_rect.emplace_back(
                    make_pair(max_x - dist, min_x + dist),
                    make_pair(max_y - dist, min_y + dist));
        }
        result = min(result, dist[indices[0]]);
        vector< int > new_dist;
        get_all_min_dist(all_rect, metro, new_dist);
        for (int i = 0; i < n - 1; ++i) {
            int t1 = add_dist[i];
            int t2 = new_dist[i];
            int t3 = dist[indices[i + 1]];
            int x = (max(0, min(2 * t2, t3 + t2 - t1)) + 1) / 2;
            result = min(result, max(t1 + x, t3 + t2 - x));
        }
    }
    result = (result + 1) / 2;
    cout << result << '\n';
    return 0;
}