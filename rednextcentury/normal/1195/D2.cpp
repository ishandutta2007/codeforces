#include<bits/stdc++.h>
using namespace std;
int n;
string a[1000000];
vector<int> f[12][12];
vector<int> s[12][12];
long long P[1000000];
long long num[1000000];
long long mod = 998244353;
void calc(int i,int j)
{
    int l=i,r=j;
    vector<int> v;
    while(l || r)
    {
        if (l>=r)
            v.push_back(1),l--;
        else
            v.push_back(0),r--;
    }
    reverse(v.begin(),v.end());
    for (int x=0;x<v.size();x++)
    {
        if (v[x]==0)s[i][j].push_back(x);
        else f[i][j].push_back(x);
    }
    reverse(s[i][j].begin(),s[i][j].end());
    reverse(f[i][j].begin(),f[i][j].end());
}
int main()
{
    //memset(dp,-1,sizeof(dp));
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    P[0]=1;
    for (int i=1;i<100;i++)
    {
        P[i]=(P[i-1]*10)%mod;
    }
    for (int i=0;i<n;i++)
        cin>>a[i],num[a[i].size()]++;
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
            calc(i,j);
    long long ret=0;
    for (int i=0;i<n;i++)
    {
        int len = a[i].size();
        //num[len]--;
        for (int j=1;j<=10;j++)
        {
            long long contrib=0;
            for (int x=0;x<len;x++)
                contrib+=P[f[len][j][x]]*(a[i][x]-'0'), ret%=mod;
            for (int x=0;x<len;x++)
                contrib+=P[s[j][len][x]]*(a[i][x]-'0'), ret%=mod;
            contrib = contrib*num[j];
            contrib%=mod;
            ret=ret+contrib;
            ret%=mod;
        }
        //num[len]++;
    }
    cout<<ret<<endl;
}