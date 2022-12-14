//In the name of God
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 120;
long long dp[(1 << 20)];
const long long oo = (long long)2e18;
int coin[Maxn];
pair<int,int> mon[Maxn];
int mask[Maxn];
int main(){
    int n,m,b;
    cin >> n >> m >> b;
    for(int i = 0; i < n;i++){
        cin >> coin[i];
        cin >> mon[i].first;
        mon[i].second = i;
        int mi;
        cin >> mi;
        for(int j = 0;j < mi;j++){
            int prob;
            cin >> prob;
            mask[i] += (1 << (prob-1));
        }
    }
    sort(mon,mon+n);
    for(int j = 0; j < (1 << m);j++)
        dp[j] = oo;
    dp[0] = 0;
    long long ans = oo;
    for(int i = 0;i < n;i++){
        for(int j = (1 << (m))-1;j >= 0;j--)
            if(dp[j] != oo)
                dp[j | mask[mon[i].second]] = min(dp[j | mask[mon[i].second]],dp[j] + coin[mon[i].second]);
        ans = min(ans,dp[(1 << m)-1] + (long long)b * mon[i].first);
    }
    if(ans == oo)
        ans = -1;
    cout << ans << endl;
    return 0;
}