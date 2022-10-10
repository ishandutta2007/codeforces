#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    unordered_set<int> st;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        st.insert(a);
    }

    cout << st.size() - st.count(0) << "\n";

    return 0;
}