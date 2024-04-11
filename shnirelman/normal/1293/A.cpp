#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;


void solve() {


    int n, s, k;
    cin >> n >> s >> k;

    vector<int> a(k);
    set<int> st;
    for(int i = 0; i < k; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }

    int ans = 2e9;
    for(int i = s; i <= n; i++) {
        if(st.count(i))
            continue;

        if(i - s < abs(ans - s)) {
            ans = i;
        }

        break;
    }

    for(int i = s; i >= 1; i--) {
        if(st.count(i))
            continue;

        if(s - i < abs(ans - s)) {
            ans = i;
        }

        break;
    }

    cout  << abs(ans - s) << endl;

}

int main() {
    //  ios_base::sync_with_stdio(0);
//  cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}