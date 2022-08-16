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

string s;

int solve() {
    stack<char> st;
    int n = s.length();
    REP(i, n)
        if(st.empty()||s[i]=='A'||st.top()!='A')
            st.push(s[i]);
        else st.pop();
    int a = 0, b = 0;
    while(!st.empty()) {
        char c = st.top(); st.pop();
        if (c == 'A') a++;
        else b++;
    }
    return a + (b&1);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>s;
        cout<<solve()<<"\n";
    }
    
    return 0;
}