#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    pair<int, int> w[200000];
    string s;
    cin >> n;
    for (int i=0; i<n; i++) {
        int wt;
        cin >> wt;
        w[i] = make_pair(wt, i);
    }
    cin >> s;
    
    sort(w, w + n);
    stack<int> st;
    int ptr = 0;
    for (int i=0; i<2*n; i++) {
        if (s[i] == '0') {
            cout << w[ptr].second + 1 << " ";
            st.push(w[ptr++].second + 1);
        } else {
            cout << st.top() << " ";
            st.pop();
        }
    }
    
    return 0;
}