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
const int N = 10000+10;
int p[N], deg[N], cnt[N], n, x;

int main() {
    scanf("%d", &n);
    p[1] = 1;
    rep(i, 1, n-1) {
        scanf("%d", &p[i+1]);
        deg[p[i+1]] ++, deg[i+1] ++;
    }
    bool ok = 1;
    rep(i, 2, n) {
        if (deg[i] == 1)
            cnt[p[i]] ++;
    }
    rep(i, 1, n) {
        if ( (deg[i] > 1 || i == 1) )
            if (cnt[i] < 3) ok = 0;
    }
    printf("%s\n", ok ? "Yes" : "No");
}