#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> A(n);
    for(auto &i:A)cin >> i;
    sort(A.begin(), A.end());
    int ans = 0;
    ll t = 0;
    for(int i = 0; i < n; ++i){
        if(A[i] >= t) {
            ++ans;
            t += A[i];
        }
    }
    cout << ans;
    return 0;
}