#include <bits/stdc++.h>
using namespace std;
 
#ifdef SG
    #include <debug.h>
#else
    #define show(...)
    #define debug(...)
    #define deepen(...)
    #define timer(...)
#endif
 
#define ARG4(_1,_2,_3,_4,...) _4
 
#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)
 
#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)
 
#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())
 
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;
 
const ld pi = 3.1415926535897932384626433832795l;
 
template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}
 
const int INF = 1000000000;
const ll LINF = 3000000000000000000LL;

const int MAXS = 500300;
const int MAXK = 20;

struct Input {
    char s[MAXS];
    vi lb, rb;
    int n, q;
    vi l, r, k;
    bool read () {
        if (scanf("%d%d", &n, &q) != 2) {
            return 0;
        }
        int cur_len = 0;
        lb.resize(n);
        rb.resize(n);
        forn(i, n) {
            scanf(" %s", s + cur_len);
            lb[i] = cur_len;
            rb[i] = cur_len + strlen(s + cur_len);
            cur_len = rb[i] + 1;
        }
        l.resize(q), r = k = l;
        forn(i, q) {
            scanf("%d%d%d", &l[i], &r[i], &k[i]);
            --l[i], --r[i], --k[i];
        }
        return 1;
    }
 
    void init (const Input &input) {
        *this = input;
    }
};
 
struct Data: Input {
    vi ans;
    void write () {
        forn(i, q) {
            printf("%d\n", ans[i]);
        }
#ifdef SG
        puts("");
#endif
    }
     
    virtual void solve () {}
     
    virtual void clear () {
        *this = Data();
    }
};

struct List
{
    int sum = 0;
    List *l = nullptr, *r = nullptr;
    List() {}
    List(int from, int to) {
        if (from != to - 1) {
            int mid = (from + to) / 2;
            l = new List(from, mid);
            r = new List(mid, to);
        }
    }
    ~List() {
        if (l) {
            delete l;
        }
        if (r) {
            delete r;
        }
    }
};

struct Solution: Data {
    int tcol[2][MAXS];
    int tSA[2][MAXS];
    int h[MAXS];
    int SA[MAXS], rSA[MAXS];
    int lcp[MAXK][MAXS];
    int vcol[MAXS];
    int bit_cnt[MAXS];
    int slen;

    void buildSA()
    {
        slen = rb.back() + 1;
        int *ocol = tcol[0], *ncol = tcol[1];
        int *oSA = tSA[0], *nSA = tSA[1];
        int cur_cnt = n + 26;
        forn(i, n) {
            forn(j, lb[i], rb[i]) {
                vcol[j] = n + s[j] - 'a';
            }
            vcol[rb[i]] = (n - i - 1);
        } 
        forn(i, slen) {
            oSA[i] = i;
        }
        copy(vcol, vcol + slen, ocol);
        for (int len = 0; len < slen; ) {
            fill(h, h + cur_cnt + 1, 0);
            forn(i, slen) {
                oSA[i] = (oSA[i] - len + slen) % slen;
                ncol[i] = ocol[oSA[i]];
                h[ncol[i] + 1]++;
            }
            partial_sum(h, h + cur_cnt + 1, h);
            forn(i, slen) {
                nSA[h[ncol[i]]++] = oSA[i];
            }
            cur_cnt = 0;
            forn(i, slen) {
                ncol[nSA[i]] = cur_cnt;
                if (i != slen - 1 && 
                   (ocol[nSA[i]] != ocol[nSA[i + 1]] || 
                    ocol[(nSA[i] + len) % slen] != ocol[(nSA[i + 1] + len) % slen])) {
                    cur_cnt++;
                }
            }
            swap(nSA, oSA);
            swap(ncol, ocol);
            len = (len) ? len * 2 : len + 1;
        }
        copy(oSA, oSA + slen, SA);
        forn(i, slen) {
            rSA[SA[i]] = i;
        }
        for (int i = 0, cur_lcp = 0; i < slen; ++i) {
            int id = rSA[i];
            if (id == slen - 1) {
                cur_lcp = 0;
                continue;
            }
            int nid = SA[id + 1];
            if (cur_lcp) --cur_lcp;
            while (i + cur_lcp < slen && nid + cur_lcp < slen && 
                   vcol[i + cur_lcp] == vcol[nid + cur_lcp]) ++cur_lcp;
            lcp[0][id] = cur_lcp;
        }
        forn(it, 1, MAXK) {
            forn(i, slen) {
                lcp[it][i] = lcp[it - 1][i];
                int nxt = i + (1 << (it - 1));
                if (nxt < slen) {
                    umn(lcp[it][i], lcp[it - 1][nxt]);
                }
            }
        }
    }

    List *new_id(int from, int to, int add, List *node)
    {
        List *res = new List;
        res->sum = node->sum + 1;
        res->l = node->l;
        res->r = node->r;
        if (to != from + 1) {
            int mid = (from + to) / 2;
            if (add < mid) {
                res->l = new_id(from, mid, add, node->l);
            } else {
                res->r = new_id(mid, to, add, node->r);
            }
        } 
        return res;
    }

    int get_lcp(int i, int j)
    {
        if (i == j) {
            return slen - SA[i];
        }
        int it = bit_cnt[j - i];
        return min(lcp[it][i], lcp[it][j - (1 << it)]);
    }

    int sum(List *node, int l, int r, int from, int to)
    {
        int res = 0;
        if (max(l, from) < min(r, to)) {
            if (l <= from && r >= to) {
                res = node->sum;
            } else {
                int mid = (from + to) / 2;
                res = sum(node->l, l, r, from, mid) + sum(node->r, l, r, mid, to);
            }
        }
        return res;
    }

    void solve () {
        // deepen(0);
        bit_cnt[1] = 0;
        forn(i, 2, MAXS) {
            bit_cnt[i] = bit_cnt[i / 2] + 1;
        }
        buildSA();
        ve< List * > trees(slen + 1);
        trees[0] = new List(0, n);
        debug(vcol, vcol + slen);
        debug(SA, SA + slen);
        debug(lcp[0], lcp[0] + slen);
#ifdef SG
        forn(i, slen) {
            printf("% 2d: % 2d ", lcp[0][i], SA[i]);
            forn(j, SA[i], slen) {
                if (vcol[j] < n) {
                    putchar('!' + vcol[j]);
                } else {
                    putchar(vcol[j] - n + 'a');
                }
            }
            puts("");
        }
#endif
        forn(i, slen) {
            if (vcol[SA[i]] >= n) {
                int id = upper_bound(all(rb), SA[i]) - rb.begin();
                debug(mt(i, SA[i], id));
                trees[i + 1] = new_id(0, n, id, trees[i]);
            } else {
                trees[i + 1] = trees[i];
            }
        }
        ans.resize(q);
        forn(i, q) {
            int pos = rSA[lb[k[i]]];
            int ilen = rb[k[i]] - lb[k[i]];
            int lb = -1, rb = pos;
            while (lb < rb - 1) {
                int mid = (lb + rb) / 2;
                if (get_lcp(mid, pos) >= ilen) {
                    rb = mid;
                } else {
                    lb = mid;
                }
            }
            int l1 = rb;
            lb = pos, rb = slen;
            while (lb < rb - 1) {
                int mid = (lb + rb) / 2;
                if (get_lcp(pos, mid) >= ilen) {
                    lb = mid;
                } else {
                    rb = mid;
                }
            }
            int r1 = lb;
            debug(mt(k[i], l1, r1, l[i], r[i], slen));
            ++r[i];
            ans[i] = sum(trees[r1 + 1], l[i], r[i], 0, n) - sum(trees[l1], l[i], r[i], 0, n);
        }
        forn(i, slen + 1) {
            trees[i] = nullptr;
        }
    }
     
    void clear () {
        *this = Solution();
    }
};

Solution sol;

int main () {
    cout.setf(ios::showpoint | ios::fixed);
    cout.precision(20);
#ifdef SG
    freopen("input.txt", "r", stdin);
    while (sol.read())
    {
        sol.solve();
        sol.write();
        sol.clear();
    }
#else
    sol.read();
    sol.solve();
    sol.write();
#endif
    return 0;
}