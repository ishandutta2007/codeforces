#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 503;
const int MX = 1513;
int n, a[SZ];
int m[SZ];

int solve(int ci) {
    // debug(ci);
    if (ci > n) return 0;
    stack<int> st;
    int &r = m[ci];
    if (r != -1) return r;
    r = 1 + solve(ci + 1);
    for (int i = ci; i <= n; i++) {
        st.push(a[i]);
        
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            if (a != b) {
                st.push(b); st.push(a);
                break;
            } else {
                st.push(a + 1);
            }
        }

        r = min(r, (int) st.size() + solve(i + 1));
    }
    
    return r;
}

int main() {
    setIO();
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
    }
    memset(m, -1, sizeof m);
    cout<<solve(1)<<endl;
    
    return 0;
}