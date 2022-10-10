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
        int r, g, b;
        cin >> r >> g >> b;
        unordered_multiset<int> st;
        st.insert(r);
        st.insert(g);
        st.insert(b);

        int x = min({r, g, b}), y = max({r, g, b});
        st.erase(st.find(x));
        st.erase(st.find(y));
        int z = *st.begin();
        int diff = min(x, y - z), ret = diff;
        x -= diff, y -= diff;

        if (x > 0)
            y -= x / 2, z -= x / 2 + (x % 2), ret += x;
        ret += min(y, z);

        cout << ret << "\n";
    }

    return 0;
}