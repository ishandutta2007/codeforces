#include <bits/stdc++.h>
#define ll long long
using namespace std;
int pos[]={2,3,4,5,6,7,8,9};
int to[10000];
int from[100000];
int Reduce(int mask)
{
    for (int i=0;i<8;i++)
    {
        if ((1<<i)&mask)
        {
            bool ok=0;
            for (int j=i+1;j<8;j++)
            {
                if ((mask&(1<<j)) && pos[j]%pos[i]==0 && i!=j)
                    ok=1;
            }
            if (ok)mask-=(1<<i);
        }
    }
    return mask;
}
int T;
string s;
int n;
int mod=2520;
ll dp[20][75][2600][2];
int vis[20][75][2560][2];
int valid[1000][2600];
ll DP(int i,int mask,int m,bool is)
{
    if (i==n)
        return valid[mask][m];
    if (vis[i][to[mask]][m][is]==T || (is==0 && vis[i][to[mask]][m][is]))return dp[i][to[mask]][m][is];
    vis[i][to[mask]][m][is]=T;
    ll &ret = dp[i][to[mask]][m][is];
    ret=0;
    int lim = (is)?(s[i]-'0'):9;
    for (int j=0;j<=lim;j++)
    {
        bool newIs = is&&(j==s[i]-'0');
        int newMask=mask;
        if (j>1)newMask|=(1<<(j-2));
        int newMod = (m*10+j)%mod;
        ret+=DP(i+1,newMask,newMod,newIs);
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tot=(1<<8);
    set<int> ss;
    for (int i=0;i<tot;i++)
        ss.insert(Reduce(i));
    for (int i=0;i<tot;i++)
    {
        for (int j=0;j<mod;j++)
        {
            valid[i][j]=1;
            for (int x=0;x<8;x++)
            {
                if ((1<<x)&i)
                    if (j%pos[x]!=0)
                        valid[i][j]=0;
            }
        }
    }
    int cur=0;
    for (auto x:ss)
        to[x]=cur,from[cur++]=x;
    for (int i=0;i<tot;i++)
        to[i]=to[Reduce(i)];
    int t;
    cin>>t;
    while(t--){
    string l,r;
    cin>>l>>r;
    while(l.size()<20)l="0"+l;
    while(r.size()<20)r="0"+r;
    s=r;
    T++;
    n=r.size();
    long long ret = DP(0,0,0,1);
    T++;
    s=l;
    n=l.size();
    cur=0;
    for (int i=0;i<n;i++)cur=(cur*10+l[i]-'0')%mod;
    int add=1;
    for (int i=0;i<n;i++)
    {
        int v = l[i]-'0';
        if (v==0)continue;
        if (cur%v!=0)add=0;
    }
    ret-=(DP(0,0,0,1));
    ret+=add;
    cout<<ret<<endl;
    }
}