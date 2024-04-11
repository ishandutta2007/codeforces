#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
#define int long long

void solve(){
    int pls = 1, add = 0;
    multiset<int> ms;
    map<int, int> cnt;
    int res = 0;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        pls = 1 - pls;
        add = x - add;
        if (pls == 1) {
            while (!ms.empty() and *ms.begin() + add < 0) {
                cnt[*ms.begin()]--;
                ms.erase(ms.begin());
            }
        } else {
            while (!ms.empty() and -*ms.rbegin() + add < 0) {
                cnt[*--ms.end()]--;
                ms.erase(--ms.end());
            }
        }
        if (pls == 1) {
            ms.insert(x - add);
            cnt[x-add]++;
        }
        else {
            ms.insert(-(x - add));
            cnt[-(x-add)]++;
        }
        if (pls == 0)
            res += cnt[add];
        else
            res += cnt[-add];
    }
    cout << res << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}
//1 5 2 1 1 0 0