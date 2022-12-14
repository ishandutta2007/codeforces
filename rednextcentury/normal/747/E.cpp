#include<bits/stdc++.h>
using namespace std;
string S[1000000];
int num[1000000];
    string s;
void parse(int f,int l,int r)
{
    while(s[l]!=',')
    {
        S[f]+=s[l];
        l++;
    }
    l++;
    while(s[l]!=',')
    {
        num[f]=num[f]*10+(s[l]-'0');
        l++;
    }
}
bool vis[1000000];
int id;
vector<int> ret[1000000];
int mx=0;
void dfs(int lev)
{
    mx=max(mx,lev);
    ret[lev].push_back(id);
    vis[id]=1;
    int k=num[id];
    for (int j=0;j<k;j++)
    {
        id++;
        dfs(lev+1);
    }
}
int main()
{
    cin>>s;
    int z=0;
    int l=0;
    s+=",";
    int n=0;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]==',')z++;
        if (z%2==0 && z>0 && s[i]==',')
            parse(n,l,i),n++,l=i+1;
    }
    for (int i=0;i<n;i++)
        if (!vis[i])
            id=i,dfs(0);
    cout<<mx+1<<endl;
    for (int i=0;i<=mx;i++)
    {
        for (int j=0;j<ret[i].size();j++)
            cout<<S[ret[i][j]]<<' ';
        cout<<endl;
    }
}