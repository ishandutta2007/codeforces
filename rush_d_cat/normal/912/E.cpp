#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;

vector<LL> v1, v2;
int n, p[20]; LL k;

int mx, id = 0;
void dfs1(int dep, LL x) {
    if (dep >= mx) {
        v1.push_back(x);return;
    }

    dfs1(dep+1, x);
    while (1) {
        if (x > 1e18 / p[dep]) break;
        x = x * p[dep]; 
        dfs1(dep+1, x);
    }
}

void dfs2(int dep, LL x) {
    if (dep >= mx) {
        v2.push_back(x);
        return;
    }

    dfs2(dep+1, x);
    while (x <= 1e18) {
        if (x > 1e18 / p[dep]) break;
        x = x * p[dep]; 
        dfs2(dep+1, x);
    }
}

LL count(LL x) {
    LL ans = upper_bound(v1.begin(), v1.end(), x) - v1.begin();
    
    if (v2.size()) {
        ans = ans + upper_bound(v2.begin(), v2.end(), x) - v2.begin();
        for (int i = 1; i < v1.size(); i ++) {
            LL lim = x / v1[i];
            if (lim == 0) break;
            //printf("%lld %lld\n", v1[i], upper_bound(v2.begin(), v2.end(), lim) - v2.begin());
            ans += upper_bound(v2.begin(), v2.end(), lim) - v2.begin() - 1;
        }    
        ans --;
    }
    return ans;
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &p[i]);
    }
    scanf("%lld", &k);
    sort(p+1, p+1+n);

    mx = min(n+1, 6); dfs1(1, 1);
    LL ans = v1.size();

    if (n+1 >= 7) {
        mx = n+1; dfs2(6, 1);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());




    LL L = 0, R = 1e18;
    while (R - L > 1) {
        LL mid = (L + R) >> 1;
        if (count(mid) < k) {
            L = mid;
        } else {
            R = mid;
        }
    }

    cout << (L+1) << endl;
    //cout << ans << endl;


}