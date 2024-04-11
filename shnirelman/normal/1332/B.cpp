#include <bits/stdc++.h>

using namespace std;
using li = long long;

int p[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> st;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < st.size(); j++) {
            if(a[i] % st[j] == 0) {
                a[i] = -j;
                break;
            }
        }

        if(a[i] <= 0)
            continue;

        for(int j = 0; j < 11; j++)
            if(a[i] % p[j] == 0) {
                a[i] = -st.size();
                st.push_back(p[j]);
                break;
            }
    }

    cout << st.size() << endl;
    for(int i = 0; i < n; i++)
        cout << -a[i] + 1 << ' ';
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}