#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, m, k, a, b, x, y;

int solve() {
    int r = 0;
    
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        set<int> a;
        while(n--) {
            int x; cin>>x;
            a.insert(x);
        }
        bool got = false;
        int y;
        while(m--) {
            int x; cin>>x;
            if (a.count(x)) {
                got = true;
                y=x;
            }
        }
        if (got) {
            cout<<"YES\n";
            cout<<"1 "<<y<<"\n";
        } else {
            cout<<"NO\n";
        }
    }
    
    return 0;
}