#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    set<int> st;
    for (int i=0; i<n; i++)
        st.insert(i);

    int num = 0;
    for (int i=0; i<m; i++) {
        st.erase(num);
        num += 2;
        if (num >= n)
            num = 1;
    }

    int ret = 0, pred = -2;
    for (int i : st) {
        if (i - pred > 1)
            ret++;
        pred = i;
    }

    cout << ret << "\n";

    return 0;
}