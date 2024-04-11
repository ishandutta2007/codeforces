#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50, B = 62;

int n;
ll val[N], msk[N];
int low[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> val[i] >> msk[i];
        sum += val[i];
        low[i] = n;
        for(int j = B - 1; j >= 0; j--) if((msk[i] >> j) & 1) low[i] = j;
    }
    if(sum < 0) for(int i = 0; i < n; i++) val[i] = -val[i];
    ll res = 0;
    for(int b = B - 1; b >= 0; b--) {
        ll csum = 0;
        for(int i = 0; i < n; i++) {
            if(low[i] == b) csum += val[i];
        }
        if(csum > 0) {
            for(int i = 0; i < n; i++) {
                if((msk[i] >> b) & 1) val[i] = -val[i];
            }
            res |= (1LL << b);
        }
    }
    cout << res << endl;
}