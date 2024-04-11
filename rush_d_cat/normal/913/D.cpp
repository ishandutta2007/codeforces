#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstring>
#include <set>
#include <map>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define rd(x) scanf("%d", &x)
#define rd2(x, y) scanf("%d %d", &x, &y)
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i=(a);i<=(b);i++)
#define dd(x) cout << #x << " = " << x << endl;
#define max(x, y) (x > y ? x : y)
typedef pair<int, int> pii;
typedef long long LL;
const LL INF = 1000000007;
const LL MOD = 1000000007;
const int N = 200000+10;

LL n, T;
LL a[N], t[N];

struct Item {
    LL a, t; int id;
} it[N];

bool cmp(Item A, Item B) {
    return A.t < B.t;
}

vector<int> ans;
bool chk(int x) {
    int need = x; LL sum = 0;
    ans.clear();
    rep(i, 1, n) if (it[i].a >= x) {
        if (need == 0) break;
        sum += it[i].t; need --;
        ans.pb(it[i].id);
        if (need == 0) break;
    }

    if (need) return 0;
    if (sum > T) return 0;
    return 1;
}
int main() {
    scanf("%lld %lld", &n, &T);
    rep(i, 1, n) {
        scanf("%lld %lld", &it[i].a, &it[i].t); it[i].id = i;
    }
    sort(it+1, it+1+n, cmp);

    int L = 0, R = n+1;
    while (R - L > 1) {
        int mid = (L+R)>>1;
        if (chk(mid)) {
            L = mid;
        } else {
            R = mid;
        }
    }

    chk(L);

    printf("%d\n", L);
    printf("%d\n", L);
    rep(i, 0, sz(ans)-1) {
        printf("%d ", ans[i]);
    }
}