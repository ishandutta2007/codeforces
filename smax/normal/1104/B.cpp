#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int ret = 0;
    stack<char> st;
    for (int i=0; i<s.length(); i++) {
        if (!st.empty() && s[i] == st.top()) {
            ret++;
            st.pop();
        } else
            st.push(s[i]);
    }
    
    if (ret % 2 == 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    
    return 0;
}