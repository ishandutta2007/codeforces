//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 20;
const int oo = 1 << 28;
int dp[(1 << Maxn) + 9];
int cost[(1 << Maxn)][Maxn];
int c[26],ms[26],mx[26];
string mat[Maxn];
#define min(a,b) ((a) > (b)?(b):(a))
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n;i++)
        cin >> mat[i];
    for(int i = 0; i < n;i++)
        for(int j = 0; j < m;j++)
            cin >> cost[(1 << i)][j];
    for(int i = 0; i < (1 << Maxn);i++)
        for(int j = 0; j < Maxn;j++)
            dp[i] = oo;
    dp[0] = 0;
    for(int j = 0; j < m;j++){
        for(int i = 0; i < 26;i++) c[i] = 0,mx[i] = 0,ms[i] = 0;
        for(int i = 0; i < n;i++)
            c[mat[i][j] - 'a'] += cost[(1 << i)][j],mx[mat[i][j] - 'a'] = max(mx[mat[i][j] - 'a'],cost[(1 << i)][j]),ms[mat[i][j]-'a'] += (1 << i);
        for(int mask = 0; mask < (1 << n);mask++){
            for(int i = mask; i;i-=i&-i){
                dp[mask] = min(dp[mask],dp[mask ^ (i & -i)] + cost[i & -i][j]);
            }
            for(int k = 0; k < n;k++){
            	int i = mat[k][j] - 'a';
            	dp[mask | ms[i]] = min(dp[mask] + c[i] - mx[i],dp[mask | ms[i]]);
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}