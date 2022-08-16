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

int f(int i, int j, char c) {
    if (i < 0 && j >= n)
        return 1;
    if (i >= 0 && s[i] == c)
        return f(i - 1, j, c + 1);
    if (j < n && s[j] == c)
        return f(i, j + 1, c + 1);
    return 0;
}

int solve() {
    n = s.length();
    REP(i, n) if (s[i] == 'a') return f(i-1, i+1, 'b');
    return 0;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>s;
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}