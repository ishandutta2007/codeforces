#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll c[MAXN], t[MAXN];
multiset<ll> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 0; i < n; i++)
        cin >> t[i];
    if(c[0] != t[0]) {
        cout << "No\n";
        return 0;
    }
    for(int i = 1; i < n; i++)
        st.insert(c[i] - c[i - 1]);
    for(int i = 1; i < n; i++) {
        int d = t[i] - t[i - 1];
        auto it = st.find(d);
        if(it == st.end()) {
            cout << "No\n";
            return 0;
        }
        st.erase(it);
    }
    cout << "Yes\n";
}