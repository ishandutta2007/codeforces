#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

const int SZ = 400005;
int n, m;
int a[SZ];

void solve() {
    int g = 0;
    m = n / 2;
    for (int i = 0; i < m; i++)
        if (a[i] > a[i+1]) {
            g = i + 1;
            break;
        }
    if (g == 0) {
        cout<<"0 0 0"<<endl;
        return;
    }
    // cout<<"g = "<<g<<endl;

    int s = 0;
    for (int i = 2*g; i < m; i++)
        if (a[i] > a[i+1]) {
            s = i + 1;
            break;
        }
    if (s == 0) {
        cout<<"0 0 0"<<endl;
        return;
    }
    // cout<<"s = "<<s<<endl;

    int b = 0;
    for (int i = s+g; i < m; i++)
        if (a[i] > a[i+1]) {
            b = i + 1;
        }
    if (b == 0) {
        cout<<"0 0 0"<<endl;
        return;
    }
    // cout<<"b = "<<b<<endl;

    cout<<g<<" "<<(s-g)<<" "<<(b-s)<<endl;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        solve();
    }
    
    return 0;
}