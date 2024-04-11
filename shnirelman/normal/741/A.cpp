//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 6e5 + 13;
const int N2 = (1 << 24) + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 20;

/*
3 1
1 0 0
*/



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> r(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        r[a[i]]++;
    }

    int mx = 0;
    for(auto x : r)
        mx = max(mx, x);

    if(mx > 1) {
        cout << -1 << endl;
        return 0;
    }

    vector<bool> used(n, false);
    li ans = 1;
    set<int> st;
    for(int i = 0; i < n; i++) {
        if(used[i])
            continue;
        int cnt = 0;
        int v = i;

        while(!used[v]) {
            cnt++;
            used[v] = true;
            v = a[v];
        }

//        if(cnt > 1)
//            st.insert(cnt);
        if(cnt % 2 == 0)
            cnt /= 2;

        ans = ans * cnt / __gcd(cnt * 1ll, ans);
    }

    cout << ans << endl;
}