#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int a[N];

/*
1
3
1 2 3

1
5
1 4 4 5 6

1
8
6 10 56026534 405137099 550504063 784959015 802926648 967281024
*/

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    for(int i = 0; i < n; i++) {
//        int x;
        cin >> a[i];

        mp[a[i]]++;
    }

    int ans = n - 2;

//    for(auto p : mp) {
//        int cnt = p.s;
//
//        int cur = p.f;
//
//        while(true) {
//            auto it = mp.lower_bound(cur + cur - p.f);
//            if(it == mp.end())
//                break;
//
//            if(it->f == cur)
//                it++;
//
//            if(it == mp.end())
//                break;
//
////            cout << p.f << ' ' << it->f << endl;
//
//            cnt += it->s;
//            cur = it->f;
//        }
//
//        ans = min(ans, n - cnt);
//    }

    for(auto p : mp)
        ans = min(ans, n - p.s);

    for(int i = 0; i < n - 1; i++) if(a[i] < a[i + 1]) {
        int cur = a[i + 1];
        int cnt = mp[a[i]] + 1;
        while(true) {
            int j = lower_bound(a, a + n, cur + cur - a[i]) - a;
//            cout << i << ' ' << cur << ' ' << j << endl;
            if(j == n)
                break;
            cur = a[j];
            cnt++;
        }

        ans = min(ans, n - cnt);
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