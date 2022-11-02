#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define all(a) a.begin(), a.end()
#define f first
#define s second
#define int long long
/*
       ^\___/^      _
      /       \   /  \
     ( *  w  * )  \   /
     /    ^    \   \  /
     /  |><|    \  \  /
     /            V  /
     /  |   /  |  \ /
     /  |   /  #  /
     cCc/---cCc/cc'
*/

using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    vector<int> a(n);
    int sum = 0;
    int ma = 0;
    int nt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ma = max(ma, a[i]);
        if (a[i] != 0) {
            nt++;
        }
        sum += a[i];
    }
    a.push_back(0);
    sort(all(a));
    int ans = 0;
    int l = a[n];
    int cnt = 1;
    for (int i = n; i > 0; --i) {
        if (l == 1) {
            ans += i;
            break;
        }
        if  (a[i] == 0) {
            break;
        }
        if (min(a[i], l) == min(a[i-1], l)) {
            cnt++;
        }
        else {
            ans += max(cnt, min(a[i], l) - a[i-1]);
            l = min(a[i-1], max(a[i] - cnt, 1LL));
            cnt = 1;
        }
    }
    cout << max((sum - ans), (sum - (nt + ma - 1LL)));
    return 0;
}