#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n, m, v[100000], u[100000], dpv[100000], dpu[100000];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        u[i] = v[i];
    }
    sort(u, u + n);
    dpv[0] = v[0];
    dpu[0] = u[0];
    for (int i=1; i<n; i++) {
        dpv[i] = dpv[i-1] + v[i];
        dpu[i] = dpu[i-1] + u[i];
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
            cout << (l == 1 ? dpv[r-1] : dpv[r-1] - dpv[l-2]) << endl;
        else
            cout << (l == 1 ? dpu[r-1] : dpu[r-1] - dpu[l-2]) << endl;
    }
    
    return 0;
}