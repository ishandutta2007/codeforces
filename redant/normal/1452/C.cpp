#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string s;

int get(string s, char a, char b) {
    int r = 0, k = 0;
    for (char c : s)
        if (c == a) ++k;
        else if (c == b) 
            if (k) --k, ++r;
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>s;
        cout<<get(s, '(', ')') + get(s, '[', ']')<<"\n";
    }
    
    return 0;
}