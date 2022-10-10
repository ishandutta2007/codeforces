#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        if(!st.empty() && st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    }
    cout << (st.empty() ? "Yes\n" : "No\n");
}