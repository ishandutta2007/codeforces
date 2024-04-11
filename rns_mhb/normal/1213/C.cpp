#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[11];

ll solve() {
    ll m, n;
    cin >> n >> m;
    n /= m, m %= 10;
    for(int i = 1; i <= 10; i ++) a[i] = a[i-1] + i*m%10;
    cout << (n/10) * a[10] + a[n%10] << endl;
}

int main() {
    int t;
    cin >> t;
    while(t --) solve();
}