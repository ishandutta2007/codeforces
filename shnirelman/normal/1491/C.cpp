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

/*
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
//    vector<int> rg(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(n == 1) {
        cout << a[0] - 1 << '\n';
        return;
    }

    set<int> st;
    for(int i = 0; i < n; i++) {
        if(a[i] != 1)
            st.insert(i);
    }
    st.insert(n);

//    rg[n - 1] = n;
//    for(int i = n - 2; i >= 0; i--) {
//        rg[i] = (a[i + 1] > 1 ? i + 1 : rg[i + 1]);
//    }

    li ans = 0;
    int cur = 0;
    while(true) {

        while(cur < n && a[cur] == 1)
            cur++;
        if(cur == n)
            break;

        if(a[cur] >= n - cur + 1) {
            ans += (a[cur] - n + cur - 1);
            a[cur] = n - cur + 1;
        }

        int v = cur;
        ans++;

        while(v < n) {
            int u = v + a[v];
            if(a[v] > 1) {
                a[v]--;
                if(a[v] == 1) {
                    st.erase(v);
                }
                v = u;

            } else {
                v = *st.upper_bound(v);
            }


        }
    }

    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

}