#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, s, k;
        cin >> n >> s >> k;

        unordered_set<int> st;
        for (int i=0; i<k; i++) {
            int a;
            cin >> a;
            st.insert(a);
        }

        int ret = 0;
        while ((s - ret <= 0 || st.count(s - ret)) && (s + ret > n || st.count(s + ret)))
            ret++;

        cout << ret << "\n";
    }

    return 0;
}