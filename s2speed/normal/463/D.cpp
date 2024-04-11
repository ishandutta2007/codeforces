#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1020;

int dp[MAX_N] , p[MAX_N][5] , a[MAX_N][5];

int main(){
    int n , k , ans = 1;
    cin>>n>>k;
    for(int j = 0 ; j < k ; j++){
        for(int i = 0 ; i < n ; i++){
            cin>>a[i][j]; a[i][j]--;
            p[a[i][j]][j] = i;
        }
    }
    dp[0] = 1;
    for(int i = 1 ; i < n ; i++){
        int o = 1;
        for(int j = 0 ; j < i ; j++){
            int z = a[j][0] , x = a[i][0];
            bool ch = true;
            for(int q = 1 ; q < k ; q++){
                if(p[z][q] > p[x][q]){
                    ch = false;
                }
            }
            if(ch){
                o = max(dp[j] + 1 , o);
            }
        }
        dp[i] = o;
        ans = max(ans , dp[i]);
    }
    cout<<ans<<"\n";
    return 0;
}