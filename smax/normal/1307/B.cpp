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
        int n, x;
        cin >> n >> x;

        int mx = 0;
        set<int> st;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            st.insert(a);
            mx = max(mx, a);
        }

        int pos = x, ret = x / mx;
        pos %= mx;
        if (pos == 0) {
            cout << ret << "\n";
            continue;
        }
        auto it = st.lower_bound(pos);
        if (it != st.end() && *it <= x) {
            ret++;
        } else {
            ret += 2;
        }

        cout << ret << "\n";
	}

	return 0;
}