#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(x) (x).begin(), (x).end()
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || _WIN64 || __WIN32__ || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define end _end

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef long double ld;
typedef complex<double> tc;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(3e5) + 100;

int murmur(int x) {
    x ^= x >> 16;
    x *= -2048144789;
    x ^= x >> 13;
    x *= -1028477387;
    x ^= x >> 16;
    return x;
}

struct open_map {
    
    int n, sz;
    bool* used;
    int* val;
    int* cnt;
    
    open_map() {
        n = 16;
        used = new bool[n];
        val = new int[n];
        cnt = new int[n];
        for (int i = 0; i < n; ++i) {
            used[i] = false;
        }
        sz = 0;
    }
    
    int get(int nval) {
        int pos = murmur(nval) & (n - 1);
        while (used[pos]) {
            if (val[pos] == nval) {
                return cnt[pos];
            }
            pos = (pos + 1) & (n - 1);
        }
        return 0;
    }
    
    void clear() {
        n = sz = 0;
        delete[] used;
        delete[] val;
        delete[] cnt;
    }
    
    void add(int cval) {
        int pos = murmur(cval) & (n - 1);
        while (used[pos]) {
            if (val[pos] == cval) {
                ++cnt[pos];
                return;
            }
            pos = (pos + 1) & (n - 1);
        }
        if (sz + 1 + 1 >= 0.75 * n) {
            bool* nused = new bool[n * 2];
            int* nval = new int[n * 2];
            int* ncnt = new int[n * 2];
            for (int i = 0; i < n * 2; ++i) {
                nused[i] = false;
            }
            for (int i = 0; i < n; ++i) {
                if (used[i]) {
                    int pos = murmur(val[i]) & ((n * 2) - 1);
                    while (nused[pos]) {
                        pos = (pos + 1) & ((n * 2) - 1);
                    }
                    nused[pos] = true;
                    nval[pos] = val[i];
                    ncnt[pos] = cnt[i];
                }
            }
            delete[] used;
            delete[] val;
            delete[] cnt;
            used = nused;
            val = nval;
            cnt = ncnt;
            n *= 2;
            add(cval);
            return;
        }
        used[pos] = true;
        val[pos] = cval;
        cnt[pos] = 1;
        ++sz;
    }
    
};

struct seg {
    
    int l, r;
    open_map L, R;
    
};

pii a[N];
int col[N], sum[N];
seg s[N];

inline int get_cnt(open_map &map, int val) {
    return map.get(val);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int cur;
        scanf("%d", &cur);
        sum[i] = ((i > 0 ? sum[i - 1] : 0) + cur) % k;
        a[i] = mp(cur, i);
    }
    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        col[i] = -1;
    }
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        //cerr << i << " " << ans << endl;
        int pos = a[i].sc;
        int l = pos, r = pos;
        if (pos > 0 && col[pos - 1] != -1) {
            l = s[col[pos - 1]].l;
        }
        if (pos + 1 < n && col[pos + 1] != -1) {
            r = s[col[pos + 1]].r;
        }
        if (pos - l < r - pos) {
            int cur_col;
            if (r > pos) {
                cur_col = col[r];
            } else {
                cur_col = ptr++;
            }
            for (int j = l; j <= pos; ++j) {
                int need = (a[i].fs + (j > 0 ? sum[j - 1] : 0)) % k;
                if (j < pos && sum[pos] == need) {
                    ++ans;
                }
                if (r > pos) {
                    ans += get_cnt(s[col[r]].R, need);
                }
            }
            if (l < pos) {
                s[col[l]].L.clear();
                s[col[l]].R.clear();
            }
            for (int j = l; j <= pos; ++j) {
                col[j] = cur_col;
                s[cur_col].R.add(sum[j]);
                s[cur_col].L.add((j > 0 ? sum[j - 1] : 0));
                //++s[cur_col].R[sum[j]];
                //++s[cur_col].L[(j > 0 ? sum[j - 1] : 0)];
            }
            s[cur_col].l = l;
            s[cur_col].r = r;
        } else {
            int cur_col;
            if (l < pos) {
                cur_col = col[l];
            } else {
                cur_col = ptr++;
            }
            for (int j = r; j >= pos; --j) {
                int need = sum[j] - (a[i].fs % k);
                if (need < 0) {
                    need += k;
                }
                if (j > pos && (pos > 0 ? sum[pos - 1] : 0) == need) {
                    ++ans;
                }
                if (l < pos) {
                    ans += get_cnt(s[col[l]].L, need);
                }
            }
            if (r > pos) {
                s[col[r]].L.clear();
                s[col[r]].R.clear();
            }
            for (int j = r; j >= pos; --j) {
                col[j] = cur_col;
                s[cur_col].R.add(sum[j]);
                s[cur_col].L.add((j > 0 ? sum[j - 1] : 0));
                //++s[cur_col].R[sum[j]];
                //++s[cur_col].L[(j > 0 ? sum[j - 1] : 0)];
            }
            s[cur_col].l = l;
            s[cur_col].r = r;
        }
    }
    cout << ans << endl;
    return 0;
}