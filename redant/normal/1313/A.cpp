#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 3;
int n = 3, t;
int a[SZ], b[SZ];
int perm[7];
int vis[8];

int solve(int u) {
    if (u == 7) {
        for (int i = 0; i < 3; i++) b[i] = a[i];
        int r = 0;
        for (int i = 0; i < 7; i++) {
            int mask = perm[i];
            bool ok = true;
            for (int p = 0; p < 3; p++)
                if((mask>>p)&1) ok&=b[p]>0;
            if (ok) {
                r++;
                for (int p = 0; p < 3; p++)
                    if((mask>>p)&1) b[p]--;
            }
        }
        return r;
    }

    int r = 0;

    for (int i = 1; i < 8; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            perm[u] = i;
            r = max(r, solve(u+1));
            vis[i] = 0;
        }
    }

    return r;
}

int main() {
    setIO();
    cin>>t;
    while(t>0) {
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        cout<<solve(0)<<endl;
        t--;
    }
    
    return 0;
}