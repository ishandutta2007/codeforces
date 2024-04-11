#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    if(n > 26) {
        cout << -1 << endl;
        return 0;
    }
    set<int> st;
    for(int i = 0; i < n; i++)
        st.insert(s[i] - '0');
    cout << n - st.size() << endl;
}