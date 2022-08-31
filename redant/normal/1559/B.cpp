#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;
string s;
string res;
int mn;
set<string> vis;

int score(string &ss) {
    int c = 0;
    REP(i, n-1) c += ss[i] == ss[i+1];
    // cout << ss << " : " << c << endl;
    return c;
}

void tryc(string &ss) {
    REP(i, n-1) {
        if (ss[i+1] != '?')
            continue;
        if (ss[i] == 'B')
            ss[i+1] = 'R';
        else ss[i+1] = 'B';
    }
}

string solve2() {
    string s1 = s;
    if (s[0] != '?') {
        tryc(s1);
        score(s1);
        return s1;
    }
    s1[0] = 'B'; tryc(s1);
    string s2 = s; s2[0] = 'R'; tryc(s2);
    return (score(s1) < score(s2)) ? s1 : s2;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>s;
        cout<<solve2()<<"\n";
    }
    
    return 0;
}