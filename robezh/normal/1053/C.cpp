#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 500, mod = (int)1e9 + 7;

ll bit[3][N];

ll get(int t, int i){
    if(i == 0) return 0;
    ll ans = 0;
    while(i){
        ans += bit[t][i];
        if(t < 2) bit[t][i] %= mod;
        i -= (i&-i);
    }
    return ans;
}

void add(int t, int i, ll val){
    while(i < N){
        bit[t][i] += val;
        if(t < 2) bit[t][i] %= mod;
        i += (i&-i);
    }
}

int n,q,a,b;
int p[N], w[N];

ll check(int x, int l, int r){
    ll LHS = get(2, x) - get(2, l - 1);
    ll RHS = get(2, r) - get(2, x);
    return LHS - RHS;
}

int main(){
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for(int t = 0; t < 2; t++){
        for(int i = 1; i <= n; i++){
            add(t, i, 1LL * w[i] * (!t ? p[i] - i: (int)1e9 + i - p[i]));
        }
    }
    for(int i = 1; i <= n; i++) add(2, i, 1LL * w[i]);

    while(q--) {
        scanf("%d%d", &a, &b);
        if (a < 0) {
            a = -a;
            for (int t = 0; t < 2; t++) add(t, a, 1LL * (b - w[a]) * (!t ? p[a] - a : (int)1e9 + a - p[a]));
            add(2, a, 1LL * (b - w[a]));
            w[a] = b;
        }
        else{
            int l = a-1, r = b, mid;
            while(l + 1 < r){
                mid = (l + r) / 2;
                if(check(mid, a, b) <= 0) l = mid;
                else r = mid;
            }
            mid = r;
//            cout << "mid = " << mid << endl;
//            cout << get(1, mid) - get(1, a - 1) << " " << (get(2, mid) - get(2, a - 1)) << endl;
//            cout << get(0, b) << " " <<  get(0, mid) << " " << (get(2, b) - get(2, mid)) << endl;
            ll LHS = get(1, mid) - get(1, a - 1) + (get(2, mid) - get(2, a - 1)) % mod * (p[mid] - (int)1e9 - mid);
            ll RHS = get(0, b) - get(0, mid) + (get(2, b) - get(2, mid)) % mod * (mid-p[mid]);
//            cout << "LHS = " << (LHS % mod + mod) % mod << endl;
//            cout << "RHS = " << RHS << endl;
            printf("%d\n", (int)(((LHS + RHS) % mod + mod) % mod));
        }
    }
}