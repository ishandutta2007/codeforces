//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e3 + 9;
int dp[Maxn * 3],t[Maxn],q[Maxn];
int last[Maxn];
pair<int,int> sr[Maxn];
int main(){
    int n,tim;
    cin >> n >> tim;
    int mx = 0;
    for(int i = 0; i < n;i++){
        cin >> t[i] >> q[i];
        sr[i] = make_pair(tim - t[i],i);
        mx = max(mx,tim - t[i]);
    }
    sr[n] = make_pair(0,n);
    n++;
    sort(sr,sr+n);
    reverse(sr,sr+n);
    int lasth = mx;
    for(int i = 0; i < n;i++){
        int h = sr[i].first,id = sr[i].second;
        while(lasth != h){
            for(int j = 1; j < Maxn;j++)
                dp[j] = max(dp[2 * j],dp[2 * j - 1]);
            lasth--;
        }
        for(int j = Maxn - 1; j ;--j)
            dp[j] = max(dp[j],dp[j-1] + q[id]);
    }
    cout << dp[1] << endl;
    return 0;
}