#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;

const int NICO = 1002;
int n, x, y;
map<int, LL> mpx, mpy;
map<pair<int, int>, LL> mp;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d %d", &x, &y);
        mpx[x] ++, mpy[y] ++;
        mp[make_pair(x, y)] ++;
    }

    map<int, LL>::iterator it;
    map<pair<int, int>, LL>::iterator it1;
    LL ans = 0;
    for(it = mpx.begin(); it != mpx.end(); it ++) {
        LL cnt = it->second;
        ans += cnt * (cnt - 1) / 2;
    }
    for(it = mpy.begin(); it != mpy.end(); it ++) {
        LL cnt = it->second;
        ans += cnt * (cnt - 1) / 2;
    }
    for(it1 = mp.begin(); it1 != mp.end(); it1 ++) {
        LL cnt = it1->second;
        ans -= cnt * (cnt-1) / 2;
    }
    cout << ans << endl;
}