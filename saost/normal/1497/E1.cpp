#include <iostream>

using namespace std;
int t, n, k, cnt, f[10000005], prime[10000005], avail[10000005];

void eratos() {
    int NN = 1e7;
    f[1] = 1;
    for(int i=2; i<=NN; i++) {
        if (!f[i]) f[i] = prime[++cnt] = i;
        int j = 1;
        while (j<=cnt && prime[j] <= f[i] && prime[j]*i <= NN) {
            f[prime[j]*i] = prime[j];
            j++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    eratos();
    int x, vv = 0, sl;
    while (t--) {
        cin >> n >> k;
        vv++;
        sl = 1;
        for(int i=1; i<=n; i++) {
            cin >> x;
            int d = 0, v = 1, nxt = 1;
            while (f[x] > 1) {
                if (nxt == f[x]) nxt = 1; else {
                    v *= nxt;
                    nxt = f[x];
                }
                x /= f[x];
            }
            v *= nxt;
            if (avail[v] == vv) vv++, sl++;
            avail[v] = vv;
        }
        cout << sl << '\n';
    }
}