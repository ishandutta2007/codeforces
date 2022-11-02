#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 100010

ll a[N];

int main() {
    ll n, k;
    int m;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++) cin >> a[i];
    int ans = 0;
    ll R = k;
    int st = 1;
    for(int i = 1, j = 1; i <= m; i = j) {
        ans ++;
        if(R < a[i]) {
            ll g = (a[i] - R + k - 1) / k;
            R += g * k;
        }
        while(j <= m && a[j] <= R) j ++;
        R += j - i;
    }
    cout << ans << endl;
}