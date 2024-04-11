#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    multiset<int> st;
    for (int i=1; i<=k+1; i++) {
        cout << "?";
        for (int j=1; j<=k+1; j++)
            if (i != j)
                cout << " " << j;
        cout << endl;

        int pos, x;
        cin >> pos >> x;
        st.insert(x);
    }

    cout << "! " << st.count(*st.rbegin()) << endl;

    return 0;
}