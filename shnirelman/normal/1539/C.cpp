#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int LOGN = 20;
const int A = 27;

li a[N];

int main() {
//    int t = 1;
////    cin >> t;
//
//    while(t--)
//        solve();

    int n;
    li k, x;
    cin >> n >> k >> x;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int res = 1;
    multiset<li> ms;
    for(int i = 1; i < n; i++) {
        if(a[i] - a[i - 1] > x) {
            res++;
            ms.insert(a[i] - a[i - 1]);
        }
    }

    for(auto y : ms) {
        li z = (y - 1) / x;
        if(z <= k) {
            res--;
            k -= z;
        }
    }

    cout << res << endl;
}