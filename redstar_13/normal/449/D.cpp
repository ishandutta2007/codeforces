#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

#define NN (1<<20)

int cnt[NN], val[NN], bit[NN];
void gn(int &x) {
    static char c;
    while (c=getchar(), c<'0' || c>'9');
    for (x=0; c>='0'; x=(x<<3)+(x<<1)+c-'0', c=getchar());
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    
    int n, u;
    gn(n);
    for (int i=0; i<n; i++) {
        gn(u); cnt[u]++;
    }
    for (int i=0; i<20; i++) {
        int c=1<<i;
        for (int j=c; j<NN; j=c|(j+1)) {
            cnt[j^c]+=cnt[j];
        }
    }

    INT ans=0;
    const int MOD = 1000000007;
    for (int i=val[0]=1; i<NN; i++) val[i]=(val[i-1]<<1)%MOD;
    for (int i=0; i<NN; i++) {
        bit[i]=bit[i>>1]^(i&1);
        ans+=(1-2*bit[i])*val[cnt[i]];
    }
    cout << (ans%MOD+MOD)%MOD << endl;

    return 0;
}