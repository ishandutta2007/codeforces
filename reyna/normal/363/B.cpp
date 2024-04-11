#include <iostream>
using namespace std;
int arr[150001];
int dp[150001];
int main(){
    int n;
    int k;
    cin >> n >> k;
    int counter = 0;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        if(i < k){
            counter += arr[i];
        }
    }
    dp[0] = counter;
    int min1 = dp[0];
    int minandis = 0;
    for(int i = k; i < n;i++){
        dp[i-k+1] = dp[i-k]-arr[i-k]+arr[i];
        if(min1 > dp[i-k+1]){
            minandis = i-k+1;
            min1 = dp[i-k+1];
        }
        
    }
    cout << minandis+1 << endl;
    return 0;
}