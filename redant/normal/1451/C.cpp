#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 1000005;
int a[26], b[26];
string s[2];
int n, k;

bool solve() {
    REP(i, 26) a[i] = b[i] = 0;
    for (char c : s[0]) a[c-'a']++;
    for (char c : s[1]) b[c-'a']++;
    int cnt = 0;
    REP(i, 26) {
        if (a[i] == b[i]) {}
        else if (a[i] < b[i]) {
            if (a[i] + cnt < b[i])
                return false;
            cnt -= b[i] - a[i];
        } else {
            cnt += a[i] - b[i];
        }

        if (cnt % k != 0)
            return false; // ???
    }

    return true;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        cin>>s[0]>>s[1];
        cout<<(solve()?"Yes":"No")<<"\n";
    }
    
    return 0;
}