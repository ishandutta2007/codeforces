#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 100005;
int n;
LL a[SZ];

int main() {
    setIO();
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>a[i];
    sort(a, a+n);
    LL r = 1e18;
    LL cl = 1;
    LL m = a[n-1]; m*=m;
    while(pow(cl, n) < m)
        cl++;
    LL c = 1;
    for (c = 1; c < cl; c++) {
        LL p = a[0]-1;
        LL cc = c;
        for (int i = 1; i < n; i++, cc*=c) {
            p += abs(a[i]-cc);
        }
        
        if (p<r) {
            // cout<<"c="<<c<<", p="<<p<<endl;
            r=p;
        }
    }
    // cout<<"c="<<c<<", r="<<r<<endl;
    cout<<r<<"\n";
    return 0;
}