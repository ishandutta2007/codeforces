#include<bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int K = 8;
const int N = K * K;
const int LOGN = 35;
const int MOD = 998244353;
const int INF = 1e9 + 13;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for(int k = n; k >= 0; k--) {
        vector<bool> b(n, false);
        multiset<int> ms(a.begin(), a.end());
        bool res = true;
        for(int i = 0; i < k; i++) {
            while(!ms.empty() && *ms.rbegin() > k - i)
                ms.erase(prev(ms.end()));

            if(ms.empty()) {
                res = false;
                break;
            }

            ms.erase(prev(ms.end()));
            if(!ms.empty())
                ms.erase(ms.begin());
//            int j = upper_bound(a.begin(), a.end(), k - i) - a.begin() - 1;
//            if(j == -1 || b[j]) {
//                res = false;
//                break;
//            }


        }

        if(res) {
            cout << k << endl;
            return;
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}