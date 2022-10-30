
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    if (k >= n || k >= m){
        cout << -1 << endl;
        return 0;
    }

    vector<long long> va(n), vb(m);
    for (long long i = 0; i < n; ++i) cin >> va[i];
    for (long long i = 0; i < m; ++i) cin >> vb[i];

    long long best = 0;
    for (long long i = 0, j = 0; i <= k; ++i){
        while (j < vb.size() && vb[j] < va[i] + ta) ++j;
        if (j + k - i >= vb.size()){
            cout << -1 << endl;
            return 0;
        }
        best = max(best, vb[j + k - i] + tb);
    }
    cout << best << endl;

    return 0;
}