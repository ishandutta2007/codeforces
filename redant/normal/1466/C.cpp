#include <bits/stdc++.h>
#include <iomanip>
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
vector<bool> flag;

bool eq(int i, int j) {
    if (flag[i] || flag[j])
        return false;
    return s[i] == s[j];
}

int solve() {
    n = s.length();
    if (n == 1) return 0;
    if (n == 2) return s[0] == s[1];
    int r = 0;
    flag.resize(n);
    fill(flag.begin(), flag.end(), false);
    for (int i = 1; i + 1 < n; i++) {
        if (eq(i, i-1) && eq(i, i+1)) {
            flag[i] = true;
            flag[i+1] = true;
            r += 2;
        } else if (eq(i, i-1)) {
            flag[i] = true;
            r += 1;
        } else if (eq(i, i+1)) {
            flag[i+1] = true;
            r += 1;
        } else if (eq(i-1, i+1)) {
            flag[i+1] = true;
            r += 1;
        }
    }
    return r; 
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