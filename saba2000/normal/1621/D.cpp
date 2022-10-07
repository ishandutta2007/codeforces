#include<bits/stdc++.h>
using namespace std;
long long c[509][509];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long S = 0;
        for(int i = 1; i <= 2*n; i++){
            for(int j = 1; j <= 2*n; j++){
                cin >> c[i][j];
                if(i > n && j > n) S += c[i][j],c[i][j] = 0;

            }
        }
        vector<long long> v = {c[n][n+1], c[n+1][n], c[1][n+1], c[n+1][1], c[1][2*n], c[2*n][1], c[n][2*n], c[2*n][n]};
        long long ans = v[0];
        for(long long x: v){
            ans = min(ans, x);
        }
        cout <<ans+S<<endl;

    }
    //####

}