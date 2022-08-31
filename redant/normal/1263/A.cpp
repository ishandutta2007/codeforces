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
        LL a, b, c;
        cin>>a>>b>>c;
        LL sum = a+b+c;
        LL mx = max(a, max(b, c));
        LL mn = min(a, min(b, c));
        LL mid = sum-mx-mn;
        LL r = min(mn, mx - mid);
        mn -= r;
        mx -= r;
        if (mid == mx) {
            r += (mn+mx+mid)/2;
        } else {
            r += mid;
        }

        cout<<r<<endl;
    }
    
    return 0;
}