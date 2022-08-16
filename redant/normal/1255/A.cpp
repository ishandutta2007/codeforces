#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        int a, b;
        cin>>a>>b;
        int d = abs(a-b);
        int r = d/5;
        d %= 5;
        if (d == 1 || d == 2) r++;
        else if (d == 3 || d == 4) r+=2;
        cout<<r<<endl;
    }
    
    return 0;
}