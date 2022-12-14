//In the name of God
#include <iostream>
#include <vector>
using namespace std;
const int Maxn = 10;
vector<int> al[Maxn];
int n,m,k;
long long dp[(1 << Maxn)][(1 << Maxn)];
long long rec(int now,int leaf){
    if(dp[now][leaf] != -1)
        return dp[now][leaf];
//  cerr << now << " " << leaf << endl;
    long long ret = 0;
    int num = 0;
    int leafs = 0;
    for(int i = 0; i < n;i++)
        if((leaf & (1 << i)))
            leafs++;
    for(int i = 0; i < n;i++)
        if(((now & (1 << i)))){
            num++;
            if(((leaf & (1 << i)))){
                for(int j = 0; j < al[i].size();j++){
                    int u = al[i][j];
                    if(((1 << u) & now) && !((1 << u) & leaf)){
                        ret += rec(now - (1 << i),leaf - (1 << i) + (1 << u));
                        if(leafs-1 > 1)
                            ret += rec(now - (1 << i),leaf - (1 << i));
                    }
                }
            }
        }
//  cerr << ret << " : ) " << leafs << endl;
    return dp[now][leaf] = ret/leafs;
}
int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        al[--u].push_back(--v);
        al[v].push_back(u);
    }
    for(int i = 0; i < (1 << n);i++)
        for(int j = 0; j < (1 << n);j++)
            dp[i][j] = -1;
    for(int i = 0; i < n;i++)
        for(int j = 0; j < n; j++)
            if(i != j)
                dp[(1 << i) + (1 << j)][(1 << i) + (1 << j)] = 1;
    long long ans = 0;
    for(int i = 0; i < (1 << n);i++){
        int cnt = 0;
        for(int j = 0; j < n;j++)
            if((i & (1 << j)))
                cnt++;
        if(cnt == k)
            ans += rec((1 << n)-1,i);
    }
    cout << ans << endl;
    return 0;
}