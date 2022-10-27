#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int NICO = 200000+10;
vector<int> v[NICO], c[NICO], m[NICO], minc[NICO];
int n, x;
int l[NICO], r[NICO], cost[NICO];
int rk[NICO];
bool cmp(int x, int y) {
    return l[x] < l[y];
}
int main() {
    scanf("%d %d", &n, &x);
    for(int i=1;i<=n;i++) {
        scanf("%d %d %d", &l[i], &r[i], &cost[i]);
        rk[i] = i;
    }
    sort(rk+1, rk+1+n, cmp);
    for(int i=1;i<=n;i++) {
        v[r[rk[i]] - l[rk[i]] + 1].push_back(l[rk[i]]);
        c[r[rk[i]] - l[rk[i]] + 1].push_back(cost[rk[i]]);
    }
    for(int i=1;i<NICO;i++) {
        int mic = 1e9+7;
        for(int j=(int)c[i].size()-1;j>=0;j--) {
            m[i].push_back(min(mic, c[i][j]));
            mic = min(mic, c[i][j]);
        }
        for(int j=(int)m[i].size()-1;j>=0;j--) {
            minc[i].push_back(m[i][j]);
        }
    }

    int ans = 2e9+7;
    for(int i=1;i<=n;i++) {
        if(r[i]-l[i]+1 < x) {
            int num = x - (r[i]-l[i]+1);
            int pos = upper_bound(v[num].begin(),v[num].end(),r[i]) - v[num].begin();
            if(pos >= v[num].size()) {
                continue;
            } else {
                ans = min(cost[i] + minc[num][pos], ans);
            }
        }
    }
    if(ans == 2e9+7) ans = -1;
    cout << ans << endl;
}