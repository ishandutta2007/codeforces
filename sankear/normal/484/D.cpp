#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define next _next
#ifdef LOCAL42
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9) + 100;
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = (1 << 20);

struct node {
    
    int max_val;
    ll max_d, ans;
    
};

struct stack {
    
    int k;
    node s[N];
    
    stack() {
        k = 1;
        s[0].max_d = -1LL * inf * inf;
        s[0].max_val = inf;
        s[0].ans = -1LL * inf * inf;
    }
    
    ll prepare(int val) {
        ll max_d = -1LL * inf * inf;
        while (s[k - 1].max_val < val) {
            max_d = max(max_d, s[--k].max_d);
        }
        return max_d;
    }
    
    void add(ll max_d, int max_val) {
        s[k].max_d = max_d;
        s[k].max_val = max_val;
        s[k].ans = max(s[k - 1].ans, max_d + max_val);
        ++k;
    }
    
    ll get_ans() {
        return s[k - 1].ans;
    }
    
};

stack s_min, s_max;
int a[N];
ll d[N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        ll d_min = s_min.prepare(-a[i]);
        ll d_max = s_max.prepare(a[i]);
        d[i] = max(s_min.get_ans() + a[i], s_max.get_ans() - a[i]);
        d[i] = max(d[i], d_min);
        d[i] = max(d[i], d_max);
        s_min.add(max(d_min, (i > 0 ? d[i - 1] : 0)), -a[i]);
        s_max.add(max(d_max, (i > 0 ? d[i - 1] : 0)), a[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}