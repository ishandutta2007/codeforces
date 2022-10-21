#include <bits/stdc++.h>
using namespace std;

const int N = 200500;

typedef long long ll;
int n, k, dn;
int num[N];
int dig[N];
int lb = N, rb = -1;
int res = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> k;
    dn = n + 33;
    for(int i = 0; i < n + 1; i++) {
        if(i == n) {
            bool all = true;
            for(int j = 0; j < dn; j++) if(dig[j]){
                all = false;
                break;
            }
            if(all) res--;
        }
        cin >> num[i];
        int x = num[i];
        for(int k = 0; k < 33; k++) {
            dig[i+k] += x % 2;
            x /= 2;
            if(dig[i+k] >= 2) dig[i+k]-=2, dig[i+k+1]++;
            if(dig[i+k] < 0) dig[i+k]+=2, dig[i+k+1]--;
        }
    }
    if(dig[dn] == -1) {
        for(int i = 0; i < dn; i++) dig[i] = !dig[i];
        dig[0]++;
        for(int i = 0; i < dn; i++) if(dig[i] >= 2) dig[i]-=2, dig[i+1] ++;
    }
//    for(int i = 0; i < dn; i++) cout << dig[i];
//    cout << endl;
//    cout << dig[dn] << endl;
    for(int i = 0; i < dn; i++) if(dig[i]) lb = min(lb, i), rb = max(rb, i);
    for(int i = min(max(0, rb - 33 + 1), n); i <= min(n, lb); i++) {
        ll cur = 0;
        for(int k = min(32, rb - i); k >= 0; k--) {
            cur *= 2; cur += dig[i+k];
        }
//        cout << i << ", " << cur << ", " << num[i]abs(1LL * num[i] + (dig[dn] == -1 ? 1 : -1) * cur) << endl;
        if(abs(1LL * num[i] + (dig[dn] == -1 ? 1 : -1) * cur) <= k) res++;
    }
    cout << res << endl;


}