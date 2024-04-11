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
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define LLD "%lld"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#define LLD "%I64d"
#endif

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;
const int M = 10;

int m;
int a[N][M];

struct mystack {
    
    int sz;
    int val[N][M], max_val[N][M];
    
    inline void init() {
        sz = 0;
        for (int i = 0; i < m; ++i) {
            max_val[0][i] = -inf;
        }
    }
    
    void add(int cur_val[M]) {
        ++sz;
        for (int i = 0; i < m; ++i) {
            val[sz][i] = cur_val[i];
            max_val[sz][i] = max(max_val[sz - 1][i], val[sz][i]);
        }
    }
    
};

struct myqueue {
    
    mystack s1, s2;
    
    inline void init() {
        s1.init();
        s2.init();
    }
    
    inline void pop_back() {
        assert(s2.sz > 0);
        --s2.sz;
    }
    
    inline void pop_front() {
        if (s1.sz == 0) {
            while (s2.sz > 0) {
                s1.add(s2.val[s2.sz]);
                --s2.sz;
            }
        }
        assert(s1.sz > 0);
        --s1.sz;
    }
    
    inline void add(int val[M]) {
        s2.add(val);
    }
    
    inline int size() {
        return s1.sz + s2.sz;
    }
    
    inline int get_sum() {
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += max(s1.max_val[s1.sz][i], s2.max_val[s2.sz][i]);
        }
        return sum;
    }
    
    inline void put_ans(int ans[M]) {
        for (int i = 0; i < m; ++i) {
            ans[i] = max(s1.max_val[s1.sz][i], s2.max_val[s2.sz][i]);
        }
    }
    
};

myqueue q;
int ans[M];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    q.init();
    int ptr = 0, len = 0;
    for (int i = 0; i < n; ++i) {
        ptr = max(ptr, i);
        while (ptr < n) {
            q.add(a[ptr]);
            if (q.get_sum() <= k) {
                ++ptr;
            } else {
                q.pop_back();
                break;
            }
        }
        if (q.size() > len) {
            len = q.size();
            q.put_ans(ans);
        }
        if (q.size() > 0) {
            q.pop_front();
        }
    }
    cerr << "len = " << len << endl;
    for (int i = 0; i < m; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}