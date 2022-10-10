
// Problem : C. Intense Heat
// Contest : Codeforces Round #494 (Div. 3)
// URL : https://codeforces.com/contest/1003/problem/C
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

int a[5000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    double ret = 0;
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=i; j<n; j++) {
            sum += a[j];
            if (j - i + 1 >= k)
                ret = max(ret, sum / (double) (j - i + 1));
        }
    }
    
    cout << fixed << setprecision(10) << ret << "\n";

    return 0;
}