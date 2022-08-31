#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, m;

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        int d = abs(n-m);
        int r = d/10+(d%10>0);
        cout<<r<<"\n";
    }
    
    return 0;
}