#include <iostream>
using namespace std;
long long dpL[100001][2];
long long dpR[100001][2];
long long arr[100001];
long long ans[100001];
int main(){
    int n;
    cin >> n;
    n--;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    dpR[0][0] = 0;
    dpR[0][1] = 0;
    for(int i = 1; i <= n; i++){
        dpR[i][0] = dpR[i-1][0] + arr[i-1]-1+(arr[i-1]%2);
        if(dpR[i][0] < dpR[i-1][1] + arr[i-1]-(arr[i-1]%2)){
            dpR[i][0] = dpR[i-1][1] + arr[i-1]-(arr[i-1]%2);
        }
        if(arr[i-1] != 1){
            dpR[i][1] = dpR[i-1][1] + arr[i-1]-(arr[i-1]%2);
        }else{
            dpR[i][1] = 0;
        }
    //  cout << "i " << i << " " << dpR[i][0] << " " << dpR[i][1] << endl;
    }
    dpL[n][0] = 0;
    dpL[n][1] = 0;
    for(int i = n-1; i >= 0; i--){
        dpL[i][0] = dpL[i+1][0] + arr[i]-1+(arr[i]%2);
        if(dpL[i][0] < dpL[i+1][1] + arr[i]-(arr[i]%2)){
            dpL[i][0] = dpL[i+1][1] + arr[i]-(arr[i]%2);
        }
        if(arr[i] != 1){
            dpL[i][1] = dpL[i+1][1] + arr[i]-(arr[i]%2);
        }else{
            dpL[i][1] = 0;
        }
    //  cout << "i " << i << " " << dpL[i][0] << " " << dpL[i][1] << endl;
    }
    long long counter = 0;
    for(int i = 0; i < n;i++){
        counter = dpR[i][0]+dpL[i+1][1]+arr[i];
        if(counter < dpR[i][1] + dpL[i+1][0] + arr[i]){
            counter = dpR[i][1] + dpL[i+1][0] + arr[i];
        }
        ans[i] = counter;
        counter = 0;
    }
    long long max = 0;
    for(int i = 0; i < n; i++){
        if(ans[i] > max){
            max = ans[i];
        }
    }
    cout << max;
}