#include<bits/stdc++.h>
using namespace std;
#define ll long long
long double dp[20][20];
bool vis[20][20];
int a[15][15];
pair<int,int> nxt(pair<int,int> x) {
    int i = x.first, j = x.second;
    if (i%2==0) {
        j++;
        if (j==11)j=10,i--;
    } else {
        j--;
        if (j==0)j=1,i--;
    }
    return {i,j};
}
long double DP(int i,int j) {
    if (i==1 && j==1) return 0;
    if (vis[i][j])return dp[i][j];
    vis[i][j]=1;
    long double PNot = 0;
    if (i==1 && j<=6) {
        PNot = (6.0-j+1.0)/6.0;
    }
    long double ret = 0;
    pair<int,int> cur = {i,j};
    for (int i=0;i<6;i++) {
        if (cur.first==1 && cur.second==1)break;
        cur = nxt(cur);
        long double now = (1/6.0)*(DP(cur.first,cur.second)+1);
        int l  = a[cur.first][cur.second];
        if (l>0) {
            now = min(now,(1.0/6.0)*(DP(cur.first-l,cur.second)+1));
        }
        ret+=now;
    }
    ret+=PNot;
    ret/=1-PNot;
    return dp[i][j]=ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for (int i=1;i<=10;i++) {
        for (int j=1;j<=10;j++) {
            cin>>a[i][j];
        }
    }
    cout<<setprecision(10)<<fixed<<DP(10,1)<<endl;
}