#include<bits/stdc++.h>
using namespace std;
int w[100010][30],sz;
void update(string s)
{
    int k=1;
    for (int i=0; i<s.size(); i++)
    {
        int p=s[i]-'a';
        if (w[k][p]==0) {sz++; w[k][p]=sz; k=sz;} else
            k=w[k][p];
    }
}
int dfs1(int l)
{
    int p=1,g=0;
    for (int j=0; j<26; j++)
        if (w[l][j]!=0)
    {
        p=0;
        int k=dfs1(w[l][j]);
        if (k==0) g=1;
    }
    if (p==1) return 1;
    if (g==1) return 1;
    return 0;
}
int dfs2(int l)
{
    int p=0,g=0;
    for (int j=0; j<26; j++)
        if (w[l][j]!=0)
    {
        p=1;
        int k=dfs2(w[l][j]);
        if (k==0) g=1;
    }
    if (p==0) return 0;
    if (g==1) return 1;
    return 0;
}
int main()
{
    int n,m;
    cin>>n>>m;
    sz=1;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        update(s);
    }
    int d2=dfs1(1);
    int d1=dfs2(1);
    if (d1==1&&d2==1) cout<<"First"<<endl; else
    if (d1==1&&m%2==1) cout<<"First"<<endl; else
    if (d1==1) cout<<"Second"<<endl; else
    cout<<"Second"<<endl;
}