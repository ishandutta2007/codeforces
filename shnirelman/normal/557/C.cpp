#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
//const int M = 1e5 + 13;
const int A = 213;

/*
1
5
1 2 1 2 3
*/

int a[N];
int d[N];

vector<int> wh[N];

int cnt[A];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];

        wh[a[i]].push_back(i);
    }

    for(int i = 0; i < n; i++) {
        cin >> d[i];

        cnt[d[i]]++;
    }

//    cout << "saga" << endl;

    int ans = INF;
    int res = 0;
    for(int i = N - 1; i >= 0; i--) if(!wh[i].empty()) {
//        cout << i << endl;
        int rs = 0;
        for(auto j : wh[i]) {
            cnt[d[j]]--;
            rs += d[j];
        }


        int k = wh[i].size() - 1;
        int s = res;

//        cout << i << ' ' << k << ' ' << res << endl;
        for(int j = A - 1; j >= 0; j--) if(cnt[j]) {
//            cout << i << ' ' << j << ' ' << k << ' ' << cnt[j] << endl;
            if(cnt[j] <= k) {
                k -= cnt[j];
            } else {
                s += j * (cnt[j] - k);
                k = 0;
            }
        }

        res += rs;

//        cout << s << endl;

        ans = min(ans, s);
//        int k2 = k * 2 - 1;
    }

    cout << ans << endl;
}