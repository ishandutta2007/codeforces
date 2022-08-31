#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 100005;
string s;
int mn[MX];

string solve() {
    string res = "";
    int n = s.length();
    mn[n-1]=n-1;
    for (int i = n-2;i>=0;i--) {
        if (s[i] < s[mn[i+1]])
            mn[i] = i;
        else
            mn[i] = mn[i+1];
    }
    // REP(i, n) cout << mn[i];
    // cout<<endl;
    stack<char> st;
    int pos = 0;
    while (pos < n || !st.empty()) {
        if (pos == n) {
            res += st.top();
            st.pop();
            continue;
        }
        char stmn = st.empty()?('z'+1):st.top();
        if (stmn <= s[mn[pos]]) {
            res += st.top();
            st.pop();
        } else {
            st.push(s[pos++]);
        }
    }
    return res;
}

int main() {
    setIO();
    cin>>s;
    cout<<solve()<<"\n";
    return 0;
}