#include <iostream>
using namespace std;

int main()
{
    bool dp[1000005]{0};
    dp[2020] = true;
    dp[2021] = true;
    for(int i = 2022; i <= 1000000; i++){
        dp[i] = dp[i - 2020] | dp[i - 2021];
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(dp[n]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}