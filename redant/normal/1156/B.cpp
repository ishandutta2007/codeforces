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

void nope() {
    cout << "No answer\n";
}

void solve() {
    map<char, int> cnt;
    for (char c : s)
        cnt[c]++;
    string ra, rb;
    for (char c = 'a'; c <= 'z'; c += 2) {
        while (cnt[c]--) ra += c;
    }
    for (char c = 'b'; c <= 'z'; c += 2) {
        while (cnt[c]--) rb += c;
    }

    string res;
    if (ra.length() == 0) {
        res = rb;
    } else if (rb.length() == 0) {
        res = ra;
    } else if (abs(ra[ra.length()-1]-rb[0]) != 1) {
        res = ra + rb;
    } else if (abs(rb[rb.length()-1]-ra[0]) != 1) {
        res = rb + ra;
    } else {
        return nope();
    }

    cout << res << "\n";
}


int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>s;
        solve();
    }    
    return 0;
}