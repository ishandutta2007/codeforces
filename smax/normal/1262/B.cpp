#include <bits/stdc++.h>
using namespace std;

int q[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, mn = 1;
        bool solExists = true;
        vector<int> ret;
        unordered_set<int> st;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> q[i];
            if (i == 0) {
                ret.push_back(q[i]);
                st.insert(q[i]);
            } else if (q[i] > q[i-1]) {
                ret.push_back(q[i]);
                st.insert(q[i]);
            } else {
                while (mn <= q[i] && st.count(mn))
                    mn++;
                if (mn > q[i])
                    solExists = false;
                ret.push_back(mn);
                st.insert(mn);
                mn++;
            }
        }
        if (!solExists)
            cout << "-1\n";
        else {
            for (int i : ret)
                cout << i << " ";
            cout << "\n";
        }
    }

    return 0;
}