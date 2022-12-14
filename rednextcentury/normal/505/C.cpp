#include<bits/stdc++.h>
using namespace std;
int dp[30006][600];
int op[100000];
bool v[30006][600];
int l,r;
int D;
int DP(int i,int d)
{
    if (i>30000)return 0;
    if (v[i][d+250-D])return dp[i][d+250-D];
    v[i][d+250-D]=1;
    int &ret=dp[i][d+250-D];
    if (d-1>=l && i+d-1<=30000)
        ret=max(ret,DP(i+d-1,d-1)+op[i+d-1]);
    if (d+1<=r && i+d+1<=30000)
        ret=max(ret,DP(i+d+1,d+1)+op[i+d+1]);
    if (i+d<=30000)
        ret=max(ret,DP(i+d,d)+op[i+d]);
    return ret;
}
int main()
{
    int n,d;
    cin>>n>>d;
    l=max(1,d-250);
    r=d+250;
    while(n--)
    {
        int x;
        cin>>x;
        op[x]++;
    }
    D=d;
    cout<<DP(d,d)+op[d]<<endl;
}