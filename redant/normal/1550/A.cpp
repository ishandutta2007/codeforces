#include <bits/stdc++.h>
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;

int solve() {
    int r = 0;
    while (r*r < n) ++r;
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        cout<<solve()<<"\n";
    }
    
    return 0;
}