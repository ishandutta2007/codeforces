#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll dis[4000005];
ll dp[4000005];

int main()
{
    int n;
    ll m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        if(i == 1) dp[i] = 1;
        else if(i == 2) dp[i] = 2;
        else dp[i] = (dp[i - 1] + dis[i]) % m;
        for(int j = 2; j * i <= n; j++){
            dis[j * i] = (dis[j * i] + dp[i]) % m;
            if(j * i + j <= n) dis[j * i + j] = (dis[j * i + j] + m - dp[i]) % m;
        }
        dis[i + 1] = (dis[i + 1] + dp[i]) % m;
    }
    cout << dp[n] << endl;
}