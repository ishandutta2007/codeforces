#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;
string s;

void solve() {
    stack<int> st;
    for (char c : s) {
        if (c == ')') {
            cout << st.top();
            st.pop();
        } else {
            int k = 0;
            if (!st.empty() && st.top() == 0)
                k = 1;
            st.push(k);
            cout << st.top();
        }
    }
}

int main() {
    setIO();
    cin>>n>>s;
    solve();
    cout<<endl;
    return 0;
}