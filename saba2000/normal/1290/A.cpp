#include<bits/stdc++.h>
using namespace std;
int a[100009];
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(k > m - 1) k = m-1;
    int Ans = 0;
    for(int i = 0; i <= k; i++){
        int fr = i, ls = k - i;
        int ans = 1e9;
        for(int j = 0; j <= m -1- k; j++){
            ans = min(ans, max(a[fr + j + 1], a[n - ls - (m - 1- k - j)]));
        }
       Ans = max(Ans, ans);
    }
    cout << Ans << endl;
}
main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}