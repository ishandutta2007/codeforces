#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    set<int, greater<int>> st;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    int ans = 0;
    while(st.size()) {
        int x = *st.begin();
        st.erase(st.begin());
        if(x % 2 == 0) {
            ans++;
            st.insert(x / 2);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}