#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 500 + 13;
const int LOGN = 10;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
4
1 2 3 4
1
1 5
*/

void solve() {
    li n;
    int m;
    cin >> n >> m;

    vector<int> cnt(60, 0);
    li sum = 0;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;

        for(int j = 0; ; j++) {
            if(x == (1 << j)) {
                cnt[j]++;
                break;
            }
        }

        sum += x;
    }

//    cout << sum << endl;

    if(sum < n) {
        cout << -1 << endl;
        return;
    }
//    for(int i = 0; i < 60; i++) {
//        cout << i << ' ' << cnt[i] << endl;
//    }

    li ans = 0;
    for(int i = 0; i < 60; i++) {
//        cout << i << ' ' << cnt[i] << endl;
        if((1ll << i) & n) {
            for(int j = i; ; j++) {
//                cout << j << endl;
                if(cnt[j] > 0) {
                    cnt[j]--;
                    for(int k = i; k < j; k++)
                        cnt[k]++;
                    ans += j - i;
                    break;
                }
            }


        }
        cnt[i + 1] += cnt[i] / 2;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}