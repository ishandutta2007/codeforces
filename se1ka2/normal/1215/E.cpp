#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000000000;

ll d[20][20];
ll sum[20];
ll dp[1200000];

int main()
{
    ll n;
    cin >> n;
    ll a[400005];
    vector<ll> v[20];
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        a[i]--;
        sum[a[i]] += i - (ll)v[a[i]].size();
        v[a[i]].push_back(i);
    }
    for(int i = 0; i < 20; i++) v[i].push_back(10000000);
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            if(i == j) continue;
            int m = v[i].size() - 1, l = v[j].size() - 1;
            int ni = 0, nj = 0;
            while(ni < m || nj < l){
                if(v[i][ni] < v[j][nj]){
                    d[i][j] += nj;
                    ni++;
                }
                else nj++;
            }
        }
    }
    fill(dp, dp + 1200000, INF);
    dp[0] = 0;
    for(int i = 0; i < (1 << 20); i++){
        for(int j = 0; j < 20; j++){
            if(i & (1 << j)) continue;
            ll res = sum[j];
            for(int k = 0; k < 20; k++){
                if(!(i & (1 << k))) continue;
                res -= d[j][k];
            }
            dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + res);
        }
    }
    cout << dp[(1 << 20) - 1] << endl;
}