#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
 * Supports O(logS) range queries and updates on an array of items.
 * Requires that type T's combine operator is associative and
 * that T() + t = t + T() = t for all T t.
 */
template<typename T> struct seg_tree {
    int S;
    vector<T> value;

    seg_tree<T>(int S) : S(S) {
        value.resize(2 * S);
    }

    // Rebuilds all non-leaf layers of the tree in O(S)
    void rebuild() {
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }

    // Replaces the value at index i with v in O(logS)
    void upd(int i, T v) {
        i += S;
        value[i] = v;
        while (i > 1) {
            i /= 2;
            value[i] = value[2 * i] + value[2 * i + 1];
        }
    }

    // Returns the sum of the values at indices [i, j] in O(logS)
    T query(int i, int j) {
        T res_left, res_right;
        for (i += S, j += S; i <= j; i /= 2, j /= 2) {
            if ((i&1) == 1) res_left = res_left + value[i++];
            if ((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

struct time_seg {
    int begin = -1, end = -1;
    int first = -1, last = -1;
    ll rate = LLONG_MIN, total = 0, low = 0;

    time_seg() {
    }

    time_seg(int begin, int end) : begin(begin), end(end) {
        first = -1, last = -1;
    }

    time_seg(int begin, int end, int flow) : begin(begin), end(end) {
        first = begin, last = begin;
        rate = flow;
        total = rate * (end - begin);
        low = min(0ll, total);
    }

    time_seg operator+ (const time_seg& o) const {
        // one of the segments is empty, just discard it
        if (begin == -1) return o;
        if (o.begin == -1) return *this;

        // both segments contain no updates
        if (first == -1 && o.first == -1) {
            time_seg res;
            res.begin = begin, res.end = o.end;
            res.first = -1;
            return res;
        }

        // this segment contains no updates
        if (first == -1) {
            time_seg res = o;
            res.begin = begin;
            return res;
        }

        // other segment contains no updates
        if (o.first == -1) {
            time_seg res = *this;
            res.end = o.end;
            res.total += res.rate * (o.end - end);
            res.low = min(res.low, res.total);
            return res;
        }

        // both segments contain updates
        time_seg res;
        res.begin = begin, res.end = o.end;
        res.first = first, res.last = o.last;
        res.rate = o.rate;

        ll add = (o.first - end) * rate;
        res.total = total + add + o.total;
        res.low = min(low, min(total + add, total + add + o.low));
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q;
    cin >> Q;

    vi coord;

    vector<array<int, 4>> que(Q);
    for (int q = 0; q < Q; q++) {
        int op, t, s, l, r, v;
        cin >> op;
        if (op == 1) {
            cin >> t >> s;
            que[q] = { 1, t, s, 0 };
            coord.push_back(t);
        } else if (op == 2) {
            cin >> t;
            que[q] = { 2, t, 0, 0 };
            coord.push_back(t);
        } else {
            cin >> l >> r >> v;
            que[q] = { 3, l, r, v };
        }
    }

    sort(all(coord));
    coord.erase(unique(all(coord)), coord.end());
    coord.push_back(1e9 + 1);

    seg_tree<time_seg> st(coord.size());
    for (int i = 0; i + 1 < coord.size(); i++) {
        st.value[st.S + i] = time_seg(coord[i], coord[i+1]);
    }
    st.rebuild();

    for (int q = 0; q < Q; q++) {
        int op = que[q][0];
        if (op == 1) {
            int t = que[q][1], s = que[q][2];
            int i = lower_bound(all(coord), t) - coord.begin();
            st.upd(i, time_seg(coord[i], coord[i+1], s));
        } else if (op == 2) {
            int t = que[q][1];
            int i = lower_bound(all(coord), t) - coord.begin();
            st.upd(i, time_seg(coord[i], coord[i+1]));
        } else if (op == 3) {
            int l = que[q][1], r = que[q][2]; ll v = que[q][3];
            if (v == 0) {
                printf("%.6f\n", double(l));
                continue;
            }
            int i1 = lower_bound(all(coord), l) - coord.begin();
            if (coord[i1] > r) {
                printf("-1\n");
                continue;
            }

            int start = i1;
            int lo = i1, hi = coord.size() - 1;
            while (lo <= hi) {
                int mi = (lo + hi) / 2;
                time_seg ts = st.query(i1, mi);
                if (v + ts.low <= 0) {
                    hi = mi - 1;
                } else {
                    start = mi;
                    lo = mi + 1;
                }
            }

            time_seg fin = st.query(i1, start);
            if (v + fin.low <= 0) {
                double ans = fin.begin + double(v) / -fin.rate;
                if (ans > r) {
                    printf("-1\n");
                }
                else printf("%.6f\n", ans);
                    continue;
            }

            if (fin.end >= r) {
                printf("-1\n");
                continue;
            }


            ll rate = fin.rate;
            if (st.value[st.S + start + 1].first != -1) {
                rate = st.value[st.S + start + 1].rate;
            }

            assert(rate < 0);
            double ans = fin.end + double(v + fin.total) / -rate;
            if (ans > r) {
                printf("-1\n");
                continue;
            }
            printf("%.6f\n", ans);
        }
    }

    return 0;
}