#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;

int main() {
    string s;
    cin >> s;
    
    int n = s.length();
    int cnt = 0;
    int l = 0;
    stack<int> st;
    st.push(0);
    for(int i = 1; i < n; i++) {
        if(!st.empty())
            l = st.top();
        else {
            st.push(i);
            continue;
        }
            
        
        if(s[i] != s[l]) {
            l = i;
            st.push(i);
        } else {
            cnt++;
            st.pop();
        }
    }
    
    cout << (cnt % 2 == 1 ? "Yes" : "No");
}