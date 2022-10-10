#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, int> pp;
int ans[200005];
 
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ct = 0, d = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') ct++;
        else ct--;
        d = max(d, ct);
    }
    d = (d + 1)/2;
    stack<pp> st;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            st.push({'(', i});
            continue;
        }
        if(st.size() <= d) {
            ans[st.top().second] = 0;
            ans[i] = 0;
            st.pop();
        }
        else {
            ans[st.top().second] = 1;
            ans[i] = 1;
            st.pop();
        }
    }
    for(int i = 0; i < n; i++)
        cout << ans[i];
    cout << endl;
}