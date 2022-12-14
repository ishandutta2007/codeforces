//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define Rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define mkp make_pair
#define XX first
#define YY second
#define pb push_back
const int Maxn = 1e6 + 9;
typedef long long ll;
const ll oo = (ll)1e18;
vector<int> al[Maxn];
ll val[Maxn];
vector<pair<ll,int> > sub[Maxn];
ll dp[Maxn][2],ans[2],tmp[2];
void dfs(int v){
    For(i,0,al[v].size()){
        int u = al[v][i];
        dfs(u);
    }
    ans[0] = 0,ans[1] = -oo;
    tmp[0] = 0,tmp[1] = -oo;
    For(i,0,al[v].size()){
        int u = al[v][i];
        For(j,0,2)
            tmp[j] = max(ans[j ^ 1] + dp[u][1],ans[j] + dp[u][0]);
        For(j,0,2)
            ans[j] = max(ans[j],tmp[j]);
    }
    dp[v][0] = ans[0];
    dp[v][1] = max(ans[1],ans[0] + val[v]);
//  cerr << v << ' ' << dp[v][0] << ' ' << dp[v][1] << endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int root = 0;
    For(i,0,n){
        int p;
        cin >> p;
        if(p + 1)
            al[--p].push_back(i);
        else root = i;
        cin >> val[i];
    }
    dfs(root);
    cout << max(dp[root][0],dp[root][1]) << endl;
}