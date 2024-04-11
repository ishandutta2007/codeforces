#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 500;

int n;
ll num[N];
ll psum[2][N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        ll x = 0;
        scanf("%I64d", &x);
        while(x > 0) num[i] += (x % 2), x /= 2;
    }
    ll res = 0;
    for(int i = 0; i < n; i++){
        int l = i - 1;
        ll cur = 0, sum = num[i], mx = num[i];
        while(l >= max(0, i - 60)){
            sum += num[l];
            mx = max(mx, num[l]);
            if(2 * mx <= sum && sum % 2 == 0) cur++;
            l --;
        }
        if(l >= 0) cur += psum[sum % 2][l];

        for(ll t = 0; t < 2; t++){
            psum[t][i] = (i > 0 ? psum[(t + num[i]) % 2][i - 1] : 0) + (num[i] % 2 == t);
        }
        res += cur;
    }
    cout << res << endl;
}