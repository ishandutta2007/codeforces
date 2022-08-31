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

LL MX = (1ll << 32) - 1;
int n;

void over() {
    cout << "OVERFLOW!!!\n";
}

void solve() {
    LL r = 0;
    stack<LL> st;
    st.push(1);
    int oc = 0;
    while (n--) {
        string s;
        cin >> s;
        if (s == "end") {
            if (oc > 0) oc--;
            else st.pop();
        } else if (s == "add") {
            if (st.top() == -1) return over();
            r += st.top();
            if (r > MX) return over();
        } else {
            int k; cin >> k;
            if (st.top() == -1) {
                oc++;
            } else {
                st.push(st.top() * 1ll * k);
            }
            if (st.top() > MX) {
                st.pop();
                st.push(-1);
            }
        }
    }
    cout << r << endl;
}

int main() {
    setIO();
    cin>>n;
    solve();    
    return 0;
}