#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    stack<int> st;
    for(int i = 0; i < n; i++) {
        int x = s[i] - '0';
        if(!st.empty() && x != st.top()) {
            st.pop();
            continue;
        }
        st.push(x);
    }
    cout << st.size() << endl;
}