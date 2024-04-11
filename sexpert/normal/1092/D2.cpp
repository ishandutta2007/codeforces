#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int m = *(max_element(a.begin(), a.end()));
    stack<int> st;
    for(auto x : a) {
        if(!st.empty() && st.top() < x) {
            cout << "NO\n";
            return 0;
        }
        if(x == m)
            continue;
        if(st.empty() || st.top() != x)
            st.push(x);
        else
            st.pop();
    }
    cout << (st.empty() ? "YES" : "NO") << endl;
}