#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    vector<int> v1, v2;
    int x = 0, tot = 0;
    while(tot + x + 1 <= a + b) {
        tot += x + 1;
        x++;
    }
    set<int> st;
    for(int i = 1; i <= x; i++)
        st.insert(i);

    while(st.size()) {
        auto it = st.upper_bound(a);
        if(it == st.begin()) {
            for(auto x : st)
                v2.push_back(x);
            break;
        }
        --it;
        int x = *it;
        v1.push_back(x);
        a -= x;
        st.erase(x);
    }

    cout << v1.size() << '\n';
    for(auto x : v1)
        cout << x << " ";
    cout << '\n' << v2.size() << '\n';
    for(auto x : v2)
        cout << x << " ";
    cout << '\n';
}