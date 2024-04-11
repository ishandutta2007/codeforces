#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n+1), prv(n+1);
    map <int, int> last;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        prv[i] = last[a[i]];
        last[a[i]] = i;
    }
    vector <vector <int> > L(30, vector <int> (n+2));
    vector <vector <int> > R(30, vector <int> (n+2));
    for(int k = 0; k < 30; k ++) {
        L[k][0] = 0, R[k][n+1] = n+1;
        for(int i = 1; i <= n; i ++) {
            if(a[i] >> k & 1) L[k][i] = i;
            else L[k][i] = L[k][i-1];
        }
        for(int i = n; i; i --) {
            if(a[i] >> k & 1) R[k][i] = i;
            else R[k][i] = R[k][i+1];
        }
    }
    long long ans = 1ll * n * (n+1) / 2;
    for(int i = 1; i <= n; i ++) {
        int le = prv[i], ri = n+1;
        for(int j = 0; j < 30; j ++) if(a[i]>>j&1^1) le = max(le, L[j][i]), ri = min(ri, R[j][i]);
        ans -= 1ll * (i-le) * (ri-i);
    }
    cout << ans << endl;
}