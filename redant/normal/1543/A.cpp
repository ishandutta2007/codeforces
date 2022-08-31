#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL a, b;

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>a>>b;
        if (a == b) {
            cout << "0 0\n";
        } else {
            if (a < b) swap(a, b);
            LL g = a - b;
            LL s = b - g * (b / g);
            s = min(s, (b / g + 1) * g - b);
            cout << g << " " << s << "\n";
        }
    }
    
    return 0;
}