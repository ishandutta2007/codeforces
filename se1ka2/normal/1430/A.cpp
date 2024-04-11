#include <iostream>
using namespace std;

struct P
{
    int a, b, c;
};

int main()
{
    int t;
    cin >> t;
    P dp[1002];
    dp[0] = (P){0, 0, 0};
    for(int i = 1; i < 1002; i++){
        dp[i] = (P){-1, -1, -1};
        if(i >= 3 && dp[i - 3].a != -1){
            dp[i] = dp[i - 3];
            dp[i].a++;
        }
        if(i >= 5 && dp[i - 5].a != -1){
            dp[i] = dp[i - 5];
            dp[i].b++;
        }
        if(i >= 7 && dp[i - 7].a != -1){
            dp[i] = dp[i - 7];
            dp[i].c++;
        }
    }
    while(t--){
        int n;
        cin >> n;
        if(dp[n].a == -1) cout << -1 << endl;
        else cout << dp[n].a << " " << dp[n].b << " " << dp[n].c << endl;
    }
}