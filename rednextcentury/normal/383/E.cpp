#include<bits/stdc++.h>
using namespace std;
int F[20000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        string t;
        cin>>t;
        bool vis[26]={0};
        string s="";
        for (int j=0;j<t.size();j++)
        {
            if (vis[t[j]-'a']==0)s+=t[j];
            vis[t[j]-'a']=1;
        }
        for (int j=1;j<(1<<((int)s.size()));j++)
        {
            int mask=0;
            for (int x=0;x<s.size();x++)
                if ((1<<x)&j)
                    mask|=(1<<(s[x]-'a'));
            if (__builtin_popcount(mask)%2)F[mask]+=1;
            else F[mask]-=1;
        }
    }
    for (int i=0;i<24;i++)
        for (int j=0;j<(1<<24);j++)
            if (j&(1<<i))
                F[j]+=F[j^(1<<i)];
    long long ret=0;
    for (int i=0;i<(1<<24);i++)
    {
        long long cur=F[i];
        ret^=cur*cur;
    }
    cout<<ret<<endl;
}