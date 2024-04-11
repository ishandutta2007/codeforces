#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int m[n];
    int x[n];
    memset(x, 0, sizeof(x));
    vector<int> st;
    
    for(int i = 0; i < n; i++) {
        cin >> m[i];
        while(i - (int)st.size() < m[i]) {
            x[st.back()] = 1;
            st.pop_back();
        }
        if(m[i] == i - (int)st.size()) {
            x[i] = 1;
        } else {
            st.push_back(i);
        }
    }
    int ans = 0;
    int total = 0;
    for(int i = 0; i < n; i++) {
        total += x[i];
        ans += total - m[i] - 1;
    }
    cout << ans << endl;
    return 0;
}