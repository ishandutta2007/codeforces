#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 100005;
int a[MX];
int n;

void alt(int i, int v) {
    for (; i <= n; i+=2, v+=2) {
        a[i] = v + 1;
        a[i+1] = v;
    }
}

void solve() {
    if (n%2 == 0)
        alt(1, 1);
    else {
        a[1] = 1;
        alt(2, 2);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        solve();
    }
    
    return 0;
}