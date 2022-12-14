//In the name of God
#include <iostream>
#include <vector>
using namespace std;
const int Maxn = 23;
bool dp[(1 << Maxn)][Maxn];
int arr[Maxn];
vector<int> sum[Maxn][Maxn];
void upd(int mask,int stage){
    if(dp[mask][stage]){
        for(int i = 0; i <= stage;i++){
            if((mask & (1 << i)))
                for(int j = 0; j < sum[i][stage+1].size();j++){
                    if((mask & (1 << sum[i][stage+1][j]))){
                        for(int k = 0; k <= stage;k++){
                            if(mask & (1 << k)){
                                dp[mask - (1 << k) + (1 << (stage + 1))][stage+1] = true;
                            }
                        }
                        dp[mask + (1 << (stage + 1))][stage+1] = true;
                        return;
                    }
                }
        }
    }
    return;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n;i++){
        for(int j = i + 1;j < n;j++){
            for(int k = i; k < j;k++){
                if(arr[i] + arr[k] == arr[j]){
                    sum[i][j].push_back(k);
                    if(i != k)
                        sum[k][j].push_back(i);
                }
            }
        }
    }
    dp[1][0] = 1;
    upd(1,0);
    for(int i = 1; i < n - 1;i++){
        for(int mask = 0; mask < (1 << (i + 1));mask++){
            upd(mask,i);
        }
    }
    int ans = 100;
    for(int mask = 0; mask < (1 << n);mask++){
        if(dp[mask][n-1]){
            int cnt = 0;
            for(int j = 0; j < n;j++){
                if(mask & (1 << j))
                    cnt++;
            }
            ans = min(ans,cnt);
        }
    }
    if(ans != 100)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}