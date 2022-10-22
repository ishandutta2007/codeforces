#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    set<int> st;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;

        if(a[i] == i)
            ans++;
        else
            st.insert(a[i]);
    }

    cout << ans + st.size() / 2 << endl;
}