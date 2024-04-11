# include <bits/stdc++.h>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;
string s[10001];
char c[10000];
int no[100000];
string col[10000];
map<string,int> vis;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        string a,b;
        cin>>a>>b;
        s[i]=a.substr(0,3);
        c[i]=b[0];
    }
    for (int i=0;i<n;i++)
        col[i]=s[i];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if (s[i]==s[j]){

                col[i]=s[i].substr(0,2)+c[i],col[j]=s[j].substr(0,2)+c[j];
                if ((vis[col[i]]&&no[i]==0) || (vis[col[j]]&&no[j]==0) || col[i]==col[j]){
                    cout<<"NO"<<endl;
                    return 0;
                }
                vis[col[i]]=1,vis[col[j]]=1,no[i]=1,no[j]=1;
            }
        }
    }
    for (int j=0;j<n;j++){
    for (int i=0;i<n;i++)
    {
        if (no[i])continue;
        if (vis[col[i]]==1)
        {
            col[i][2]=c[i];
            if (vis[col[i]]==1)
            {
                cout<<"NO\n"<<endl;
                return 0;
            }
            else
                vis[col[i]]=1;
            no[i]=1;
        }
    }}

    cout<<"YES"<<endl;
    for (int i=0;i<n;i++)
        cout<<col[i]<<'\n';
}