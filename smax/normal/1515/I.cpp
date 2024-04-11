#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int LOG = 17;
const long long INF = 1e18L + 5;

template<typename T>
struct BIT {
    int n, lg;
    vector<T> bit;

    BIT(int _n) : n(_n), lg(__lg(n)), bit(n + 1) {}

    BIT(const vector<T> &a) : n((int) a.size()), lg(__lg(n)), bit(n + 1) {
        for (int i=1; i<=n; i++) {
            bit[i] += a[i-1];
            if (i + (i & -i) <= n)
                bit[i+(i&-i)] += bit[i];
        }
    }

    T query(int i) {
        T ret = 0;
        for (i++; i>0; i-=i&-i)
            ret += bit[i];
        return ret;
    }

    T query(int l, int r) {
        return l > r ? 0 : query(r) - query(l - 1);
    }

    void update(int i, T val) {
        for (i++; i<=n; i+=i&-i)
            bit[i] += val;
    }

    int kth(T k) {
        int ret = 0;
        for (int i=lg; i>=0; i--) {
            ret += 1 << i;
            if (ret <= n && bit[ret] < k)
                k -= bit[ret];
            else
                ret -= 1 << i;
        }
        return ret;
    }
};

struct SegmentTree {
    struct Node {
        int l, r;
        long long ans = 0, lazy = 0;

        void leaf(long long val) {
            ans += val;
        }

        void pull(const Node &a, const Node &b) {
            ans = min(a.ans, b.ans);
        }

        void push(long long val) {
            lazy += val;
        }

        void apply() {
            ans += lazy;
            lazy = 0;
        }
    };

    int n;
    vector<int> a;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), a(n), st(4*n) {
        build(1, 0, n-1);
    }

    SegmentTree(const vector<int> &_a) : n((int) _a.size()), a(_a), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        st[p].l = l;
        st[p].r = r;
        if (l == r) {
            st[p].leaf(INF);
            return;
        }
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void push(int p) {
        if (st[p].lazy) {
            if (st[p].l != st[p].r) {
                st[2*p].push(st[p].lazy);
                st[2*p+1].push(st[p].lazy);
            }
            st[p].apply();
        }
    }

    // Node query(int p, int i, int j) {
    //     push(p);
    //     if (st[p].l == i && st[p].r == j)
    //         return st[p];
    //     int m = (st[p].l + st[p].r) / 2;
    //     if (j <= m)
    //         return query(2*p, i, j);
    //     else if (i > m)
    //         return query(2*p+1, i, j);
    //     Node ret, ls = query(2*p, i, m), rs = query(2*p+1, m+1, j);
    //     ret.pull(ls, rs);
    //     return ret;
    // }

    // int query(int i, int j) {
    //     return query(1, i, j).ans;
    // }

    void update(int p, int i, int j, long long val) {
        if (st[p].l == i && st[p].r == j) {
            st[p].push(val);
            push(p);
            return;
        }
        push(p);
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m) {
            update(2*p, i, j, val);
            push(2*p+1);
        } else if (i > m) {
            push(2*p);
            update(2*p+1, i, j, val);
        } else {
            update(2*p, i, m, val);
            update(2*p+1, m+1, j, val);
        }
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, long long val) {
        update(1, i, j, val);
    }

    int walk(int p, int i, long long c) {
        push(p);
        if (i > st[p].r || st[p].ans > c)
            return -1;
        if (st[p].l == st[p].r)
            return st[p].l;
        int ret = walk(2 * p, i, c);
        if (ret == -1)
            ret = walk(2 * p + 1, i, c);
        return ret;
    }

    int walk(int i, long long c) {
        return walk(1, i, c);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    vector<int> w(n), v(n);
    for (int i=0; i<n; i++)
        cin >> a[i] >> w[i] >> v[i];

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) -> bool {
        if (v[i] == v[j])
            return w[i] < w[j];
        return v[i] > v[j];
    });

    vector<int> pos(n);
    vector totW(LOG, vector<long long>(n)), totV(LOG, vector<long long>(n));
    vector<SegmentTree> st(LOG, n);
    for (int i=0; i<n; i++) {
        pos[order[i]] = i;
        if (a[order[i]] > 0) {
            int b = __lg(w[order[i]]);
            for (int j=b; j<LOG; j++) {
                totW[j][i] = a[order[i]] * w[order[i]];
                totV[j][i] = a[order[i]] * v[order[i]];
                if (j == b)
                    st[j].update(i, i, w[order[i]] - INF);
                else
                    st[j].update(i, n - 1, a[order[i]] * w[order[i]]);
            }
        }
    }

    vector<BIT<long long>> bitW, bitV;
    for (int i=0; i<LOG; i++) {
        bitW.emplace_back(totW[i]);
        bitV.emplace_back(totV[i]);
    }

    for (int i=0; i<q; i++) {
        int t;
        cin >> t;
        if (t == 3) {
            long long c;
            cin >> c;
            int last = -1;
            long long ret = 0;
            for (int j=LOG-1; j>=0; j--) {
                int k = bitW[j].kth(c + 1 + bitW[j].query(last)) - 1;
                c -= bitW[j].query(last + 1, k);
                ret += bitV[j].query(last + 1, k);
                last = k;
                if (k + 1 < n && w[order[k+1]] <= c) {
                    k++;
                    long long take = min(c / w[order[k]], a[order[k]]);
                    c -= take * w[order[k]];
                    ret += take * v[order[k]];
                    last = k;
                }
                if (k + 1 < n) {
                    k = st[j].walk(k + 1, c + (j > 0 ? bitW[j-1].query(last) : 0));
                    if (k != -1) {
                        if (j > 0) {
                            c -= bitW[j-1].query(last + 1, k - 1);
                            ret += bitV[j-1].query(last + 1, k - 1);
                        }
                        long long take = min(c / w[order[k]], a[order[k]]);
                        c -= take * w[order[k]];
                        ret += take * v[order[k]];
                        last = k;
                    }
                }
            }
            cout << ret << "\n";
        } else {
            int k, d;
            cin >> k >> d;
            d--;
            bool wasZero = a[d] == 0;
            a[d] += (t == 1 ? 1 : -1) * k;
            int b = __lg(w[d]);
            for (int j=b; j<LOG; j++) {
                bitW[j].update(pos[d], (long long) (t == 1 ? 1 : -1) * k * w[d]);
                bitV[j].update(pos[d], (long long) (t == 1 ? 1 : -1) * k * v[d]);
                if (j == b) {
                    if (wasZero)
                        st[j].update(pos[d], pos[d], w[d] - INF);
                    else if (a[d] == 0)
                        st[j].update(pos[d], pos[d], INF - w[d]);
                } else {
                    st[j].update(pos[d], n - 1, (long long) (t == 1 ? 1 : -1) * k * w[d]);
                }
            }
        }
    }

    return 0;
}