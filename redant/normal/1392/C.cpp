// https://codeforces.com/contest/1392/problem/A
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 200005;
LL a[SZ];

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        for (int i = 0; i < n; i++)
            cin>>a[i];
        LL ans = 0;
        LL k = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] + k < a[i-1]) {
                LL kk = a[i - 1] - a[i] - k;
                ans += kk;
                k += kk;
            }
            a[i] += k;
        }
        cout<<ans<<"\n";
    }
    return 0;
}