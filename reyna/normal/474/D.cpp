#include <iostream>
using namespace std;
const int md = 1000*1000*1000+7;
int dp[123456];
int sum[123456];
int main(){
    int t,k;
    cin >> t >> k;
    dp[0] = 1;
    for(int i = 1; i <= 100000;i++){
        dp[i]+=dp[i-1];
        dp[i]%=md;
        if(i >= k){
            dp[i]+=dp[i-k];
            dp[i]%=md;
        }
    //  cout << dp[i] << endl;
    }
    sum[0] = 1;
    for(int i = 1; i <= 100000;i++){
        sum[i] = sum[i-1]+dp[i];
        sum[i]%=md;
    //  cout << i << " " << sum[i] << endl;
    }
    for(int i = 0; i < t;i++){
        int a,b;
        cin >> a >> b;
        if(a == 1){
            cout << sum[b]-1 << endl;
            continue;
        }
        cout << ((sum[b]-sum[a-1])+md)%md << endl;
    }
    return 0;
}