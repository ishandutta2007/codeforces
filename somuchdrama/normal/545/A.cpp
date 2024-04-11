#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n;
     cin >> n;
     vector<int> A(n, 1);
     for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int t;
            cin >> t;
            if(t == 1){
                A[i] = 0;
            }
            if(t == 2){
                A[j] = 0;
            }
            if(t == 3){
                A[i] = A[j] = 0;
            }
        }
     }
     int ans = 0;
     for(int i = 0; i < n; ++i){
        if(A[i]) ++ans;
     }
     cout << ans << '\n';
     for(int i = 0; i < n; ++i){
        if(A[i]) cout << (i + 1) << ' ';
     }
    return 0;
}