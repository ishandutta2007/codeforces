#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;
// 6, 2, 5, 5, 4, 5, 6, 3, 8, 7

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        if (n&1) { cout<<"7"; n-= 3; }
        while (n > 1) { cout<<"1"; n-=2; }
        cout<<"\n";
    }
    
    return 0;
}