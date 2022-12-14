#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
pair<pair<int,int> , int > arr[5001];
int par[5001];
int dp[5001];
int N = 0;
int Find_Par_Seq(int x){
    N++;
    if(par[x]!=-1)
        Find_Par_Seq(par[x]);
    else
        cout << N << endl;
    cout << arr[x].second << " ";
}
int main(){
    int n,w,h;
    cin >> n >> w >> h;
    int ptr = 0;
    for(int i = 0; i < n;i++){
        int a,b;
        cin >> a >> b;
        if(a > w && b > h){
            arr[ptr].second = i+1;
            arr[ptr].first.first = a;
            arr[ptr].first.second = b;
            dp[ptr] = 1;
            par[ptr] = -1;
            // dp hame bayad 1 bashe fargh nadare(felan)
            ptr++;
        }
    }
    n = ptr;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    sort(arr,arr+n);
    int tmp = 0;
    for(int i = 1; i < n;i++){
        for(int j = 0; j < i;j++){
            if(arr[i].first.second > arr[j].first.second && arr[i].first.first != arr[j].first.first && dp[par[i]] <= dp[j]){
                par[i] = j;
            }
        }
        dp[i] = dp[par[i]]+1;
        tmp = (dp[i]>dp[tmp])?i:tmp;
    }
    Find_Par_Seq(tmp);
    cout << endl;
    return 0;
}