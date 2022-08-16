#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL a, b, x, y, n;

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>a>>b>>x>>y>>n;
        LL full = a-x + b-y;
        LL excess = full-n;
        LL r = x*y;
        if (excess > 0) {
            LL fx = min(excess, a-x);
            LL nexcess=excess-fx;
            LL xx=x+fx;
            LL yy=y;
            if (nexcess>0) yy+=nexcess;
            LL r1=xx*yy;

            swap(x, y); swap(a, b);
            fx = min(excess, a-x);
            nexcess=excess-fx;
            xx=x+fx;
            yy=y;
            if (nexcess>0) yy+=nexcess;
            LL r2=xx*yy;

            r=min(r1, r2);
        }
        cout<<r<<"\n";
    }
    
    return 0;
}