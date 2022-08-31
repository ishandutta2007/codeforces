#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 102;
bool b[SZ], g[SZ];
int n, m;

bool solve() {
    for (int i = 0; i < 2 * n * m; i++)
        b[i%n] = g[i%m] = (b[i%n] || g[i%m]);
    for (int i = 0; i < n; i++) {
        if (!b[i]) return false;
    }
    for (int i = 0; i < m; i++) {
        if (!g[i]) return false;
    }
    return true;
}

int main() {
    setIO();
    cin>>n>>m;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        b[x] = true;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        g[x] = true;
    }
    cout<<(solve()?"Yes":"No")<<"\n";
    
    return 0;
}