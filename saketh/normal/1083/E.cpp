#include <functional>
#include <limits>

template<typename T, bool T_integral = std::is_integral<T>::value>
struct line {
    static constexpr T infinity = std::numeric_limits<T>::has_infinity ?
        std::numeric_limits<T>::infinity() : std::numeric_limits<T>::max();

    T a, b;
    mutable T intersects_next = infinity;

    T evaluate(T x) const {
        return a * x + b;
    }

    static T div(const T &a, const T &b) {
        if constexpr (T_integral)
            return a / b - ((a ^ b) < 0 && (a % b));
        else
            return a / b;
    }

    T compute_intersection(const line<T> &o) const {
        if (a == o.a) return b > o.b ? infinity : -infinity;
        return div(o.b - b, a - o.a);
    }
};

// {{{ data_structures/line }}}

#include <vector>
#include <cassert>

template<typename T>
struct line_container_monotonic : std::vector<line<T>> {
    line_container_monotonic() {}

    template<typename InputIterator>
    line_container_monotonic(InputIterator first, InputIterator last) {
        auto cmp = [](const line<T> &p, const line<T> &q) {
            return p.a < q.a;
        };

        if (std::is_sorted(first, last, cmp)) {
            for (InputIterator iter = first; iter != last; iter++)
                insert_line(iter->a, iter->b);
            return;
        }

        std::vector<T> sorted(first, last);
        std::sort(sorted.begin(), sorted.end(), cmp);

        for (const line<T> &p : sorted)
            insert_line(p.a, p.b);
    }

    /* Inserts the line f(x) = a * x + b.
     * a must be non-decreasing across calls.
     */
    void insert_line(T a, T b) {
        line<T> ins = { a, b };

        if (!this->empty()) {
            auto it = this->rbegin();

            if (it->a > a)
                assert(false);

            if (it->a == a && it->b >= b)
                return;

            it->intersects_next = it->compute_intersection(ins);

            while (this->size() >= 2 && next(it)->intersects_next >= it->intersects_next) {
                this->pop_back();
                it = next(it);
                it->intersects_next = it->compute_intersection(ins);
            }
        }

        this->push_back(ins);
    }

    /* Returns the maximum value at x among all inserted lines.
     */
    T get_maximum(T x) const {
        assert(!this->empty());
        return std::lower_bound(this->begin(), this->end(), x, [](const line<T> &l, int _x) {
            return l.intersects_next < _x;
        })->evaluate(x);
    }

    /* Returns the maximum value at x among all inserted lines.
     * Total runtime complexity is linear over sequential calls made
     * with non-decreasing x if position is not modified externally.
     */
    T get_maximum_monotonic(T x, size_t &position) const {
        assert(!this->empty());

        if (position > this->size())
            position = this->size();

        while (position > 0 && (*this)[position - 1].intersects_next >= x)
            position--;

        while (x > (*this)[position].intersects_next)
            position++;

        return (*this)[position].evaluate(x);
    }
};

// Problem: https://codeforces.com/contest/1083/problem/E

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// {{{ data_structures/line_container_monotonic }}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    struct rectangle {
        int x, y;
        int64_t c;
    };

    vector<rectangle> rect(N);

    for (auto &[x, y, c] : rect)
        cin >> x >> y >> c;

    sort(rect.begin(), rect.end(), [](rectangle a, rectangle b) {
        return a.x < b.x;
    });

    line_container_monotonic<int64_t> lc;

    lc.insert_line(0, 0);

    int64_t ans = 0;

    size_t position = 0;

    for (auto [x, y, c] : rect) {
        int64_t best = int64_t(x) * y - c + lc.get_maximum_monotonic(-y, position);

        ans = max(ans, best);

        lc.insert_line(x, best);
    }

    cout << ans << endl;

    return 0;
}