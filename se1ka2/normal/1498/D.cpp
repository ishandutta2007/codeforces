#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    int ans[100005];
    int dp[100005];
    for(int i = 1; i <= m; i++) ans[i] = dp[i] = -1;
    dp[0] = 0;
    for(int c = 1; c <= n; c++){
        int t;
        ll x;
        int y;
        cin >> t >> x >> y;
        int d[100005];
        for(int i = 0; i <= m; i++){
            if(dp[i] >= 0) d[i] = 0;
            else d[i] = -1;
        }
        queue<ll> que;
        for(int i = 0; i <= m; i++){
            if(d[i] == 0) que.push(i);
        }
        while(que.size()){
            ll u = que.front(), v;
            que.pop();
            if(t == 1) v = u + ((x + 99999) / 100000);
            else v = (u * x + 99999) / 100000;
            if(v <= m && d[v] == -1){
                d[v] = d[u] + 1;
                ans[v] = c;
                if(d[v] < y) que.push(v);
            }
        }
        swap(dp, d);
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    cout << endl;
}