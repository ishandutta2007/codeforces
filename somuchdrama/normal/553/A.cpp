#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 1e9 + 7;
int C[1001][1001];
int main() {
    ios_base::sync_with_stdio(0);
    for(int i = 0 ; i <= 1000; ++i)for(int j = 0; j <= 1000; ++j) C[i][j] = 1;
    for(int i=0; i<=1000; ++i){
        for (int k=1; k<i; ++k){
            C[i][k] = C[i-1][k-1] + C[i-1][k];
            C[i][k] %= mod;
        }
    }
    int n;
    cin >> n;
    ll A[n];
    for(int i = 0; i < n; ++i) cin >> A[i];
    ll ans = 1;
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        --A[i];
        ans *= C[sum + A[i]][sum];
        ans %= mod;
        sum += A[i] + 1;
    }
    cout << ans << '\n';
    return 0;
}