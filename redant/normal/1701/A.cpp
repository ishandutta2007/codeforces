#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int solve() {
    int s = 0;
    for (int i = 0; i < 4; i++) { 
        int x; cin >> x; s += x; 
    }
    if (s == 0) return 0;
    if (s == 4) return 2;
    return 1;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cout<<solve()<<"\n";
    }
    
    return 0;
}