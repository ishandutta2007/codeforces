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

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        int c[2];
        c[0] = c[1] = 0;
        REP(i, 2*n) {
            int x;
            cin>>x;
            c[x%2]++;
        }
        cout<<(c[0]==c[1]?"Yes":"No")<<"\n";
    }
    
    return 0;
}