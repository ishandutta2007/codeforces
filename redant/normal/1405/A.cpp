#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 105;
int n, m;
int a[SZ];

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        for (int i = n-1; i >=0 ; i--) {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}