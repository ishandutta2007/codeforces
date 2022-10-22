#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 520;

int dp[MAX_N][MAX_N] , l[MAX_N] , ne[MAX_N] , a[MAX_N];

int main(){
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        l[i] = -1;
        ne[i] = 1e9;
    }
    for(int i = 0 ; i < n ; i++){
        cin>>a[i]; a[i]--;
        if(l[a[i]] != -1){
            ne[l[a[i]]] = i;
        }
        l[a[i]] = i;
    }
    for(int i = 0 ; i < n ; i++){
        dp[i][i] = 0;
        dp[i][i + 1] = 1;
    }
    for(int k = 2 ; k <= n ; k++){
        for(int i = 0 ; i <= n - k ; i++){
            int j = i + k , q = i , z = 1e9 , p;
            while(q < j){
                if(q + 1 == j){
                    if(i == j - 2){
                        p = 1;
                    } else {
                        p = dp[i + 1][j - 1];
                    }
                } else {
                    p = dp[i][q + 1] + dp[q + 1][j];
                }
                z = min(z , p);
                q = ne[q];
            }           
            dp[i][j] = z;
        }
    }
    cout<<dp[0][n]<<"\n";
    return 0;
}