#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll A[n][2];
    for(int i = 0; i < n; ++i){
        cin >> A[i][0] >> A[i][1];
    }
    if(n == 1){
        cout << 1;
        return 0;
    }
    int ans = 2;
    for(int i = 1; i < n - 1; ++i){
        if(A[i - 1][0] < A[i][0] - A[i][1]){
            ++ans;
            continue;
        }
        if(A[i + 1][0] > A[i][0] + A[i][1]){
            ++ans;
            A[i][0] += A[i][1];
        }
    }
    cout << ans;
    return 0;
}