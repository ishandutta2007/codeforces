#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)3e5 + 500;
int n;
ll a[N], b[N];
ll psum[N], pcon[N], psumr[N];


int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%I64d", &b[i]);

    for(int i = n; i >= 1; i--){
        psum[i] = 1LL * a[i] * (i-1) + 1LL * b[i] * (2 * n - i) + psum[i+1];
        psumr[i] = 1LL * b[i] * (i-1) + 1LL * a[i] * (2 * n - i) + psumr[i+1];
    }

    for(int i = n; i >= 1; i--) pcon[i] = pcon[i+1] + a[i] + b[i];

    ll res = 0, now = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 1){
            ll curtime = 2 * i;
            res = max(res, now + psumr[i+1] + (curtime - (i)) * pcon[i+1]);
            now += curtime * b[i+1] + (curtime + 1) * a[i+1];
            res = max(res, now);
        }
        else{
            ll curtime = 2 * i;
            res = max(res, now + psum[i+1] + (curtime - (i)) * pcon[i+1]);
            now += curtime * a[i+1] + (curtime + 1) * b[i+1];
            res = max(res, now);
//            cout << psum[n] - psum[i] << endl;
//            cout << (curtime - (i-1)) << endl;
//            cout << pcon[i+1] << endl;
//            cout << now << endl;
        }
    }
    cout << res << endl;
}