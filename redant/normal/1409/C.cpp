#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL x, y, n;

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>x>>y;
        if (n==2) {
            cout<<x<<" "<<y<<"\n";
            continue;
        }
        int mid = n - 2;
        while (mid > 0 && ((y-x)%(mid+1)) != 0) {
            mid--;
        }
        LL d = (y-x)/(mid+1);
        LL rem = n-2-mid;
        LL left = x-rem*d;
        while (left <= 0)
            left += d;
        for (int i = 0; i < n; i++)
            cout<<(left+i*d)<<" ";
        cout<<"\n";
    }
    
    return 0;
}