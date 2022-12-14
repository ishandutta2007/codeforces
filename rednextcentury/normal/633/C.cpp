#include <bits/stdc++.h>
using namespace std;
int adj[1000001][26];
int v=0;
string s[100001];
bool is_word[1000001];
map<string,string> mp;
int dp[10001];
int b[10001];
int no=0;
vector<string> vec;
int main()
{
    int n;
    cin>>n;
    string ss;
    cin>>ss;
    int m;
    cin>>m;
    for (int i=0;i<m;i++)
    {
        cin>>s[i];
        string y="";
        v=0;
        for (int j=0;j<s[i].size();j++)
        {
            char t=tolower(s[i][j]);
            y+=t;
            if (adj[v][t-'a']==0)
                adj[v][t-'a']=++no,v=no;
            else
                v=adj[v][t-'a'];
            if (j==s[i].size()-1)
                is_word[v]=1;
        }
        mp[y]=s[i];
    }
    dp[0]=1;
    for (int i=1;i<=n;i++)
    {
        v=0;
        for (int j=i;j>=1;j--)
        {


            if (adj[v][ss[j-1]-'a']==0)break;
            v=adj[v][ss[j-1]-'a'];
            if (!is_word[v])continue;
            if (dp[j-1]==1)
            {
                dp[i]=1,b[i]=j;
                break;
            }
        }
    }
    for (int i=n;i>=1;)
    {
        string cur="";
        for (int j=i;j>=b[i];j--)
        {
            cur+=ss[j-1];
        }
        i=b[i]-1;
        vec.push_back(cur);
    }
    for (int i=vec.size()-1;i>=0;i--)
    {
        cout<<mp[vec[i]]<<" ";
    }
    cout<<endl;
}