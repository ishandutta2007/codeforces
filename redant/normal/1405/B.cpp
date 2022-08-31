#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 100005;
int n, m;
LL a[SZ];

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        LL x = 0, y = 0, r = 0;      
        for (int i = 0; i < n; i++) {
            if (a[i]<0) x += -a[i];
            else y+=a[i];
            LL z = min(x, y);
            y-=z;
            x-=z;
            r+=x;
            // cout<<"x="<<x<<", y="<<y<<endl;
            x=0;
        }
        cout<<r<<endl;
    }
    
    return 0;
}