#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[400000][4][4];
int vis[400000][4][4];
vector<int> vec;
int n;
int a[1000000];
int T;
int solve(int i,int last,int first){
    if (i==n+1)return 0;
    if (vis[i][last][first]==T)return dp[i][last][first];
    vis[i][last][first]=T;
    dp[i][last][first]=1e8;
    for (int c=1;c<=3;c++){
        if ((c!=last || a[i]==a[i-1]) && (i!=n || c!=first || a[i]==a[1]))
            dp[i][last][first]=min(dp[i][last][first], max(solve(i+1,c,first),c));
    }
    return dp[i][last][first];
}
void path(int i,int last,int first){
    if (i==n+1)return;
    for (int c=1;c<=3;c++){
        if ((c!=last || a[i]==a[i-1]) && (i!=n || c!=first || a[i]==a[1]))
        {
            if (max(solve(i+1,c,first),c) == dp[i][last][first]){
                vec.push_back(c);
                path(i+1,c,first);
                return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        T++;
        a[0]=-1;
        for (int i=1;i<=n;i++) {
            cin>>a[i];
        }
        int ret=1e9;
        int best=0;
        for (int i=1;i<=3;i++){
            if (max(i, solve(2, i, i)) < ret) ret = max(i, solve(2, i, i)), best=i;
        }
        vec.push_back(best);
        path(2,best,best);
        cout<<ret<<endl;
        for (auto v:vec)cout<<v<<' ';
        cout<<endl;
        vec.clear();
    }
}