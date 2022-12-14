
#include<bits/stdc++.h>
using namespace std;
int adj[200001][26];
vector<int> re[300000];
vector<int> no[300000];
int head=0;
int cur=1;
bool palin(string s)
{
    for (int i=0;i<s.size();i++)
    {
        if (s[i]!=s[s.size()-i-1])
            return 0;
    }
    return 1;
}
vector<int> pal[300000];

int val[1000000];
void add(string s,bool rev,int id)
{
    if (rev)
        reverse(s.begin(),s.end());
    int v=head;
    for (int i=0;i<s.size();i++)
    {
        if (adj[v][s[i]-'a'])
            v=adj[v][s[i]-'a'];
        else
        {
            adj[v][s[i]-'a']=cur++;
            v=adj[v][s[i]-'a'];
        }
    }
    if (palin(s))
    {
        if (rev)return ;
        pal[v].push_back(val[id]);
    }
    else{
    if (rev)
        re[v].push_back(val[id]);
    else
        no[v].push_back(val[id]);
    }
}
string s[1000000];
int max_even[1000000];
bool comp(int i,int j)
{
    return i>j;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        cin>>s[i]>>val[i];
        add(s[i],0,i);
        add(s[i],1,i);
    }
    int mx=0;
    int ans1=0;
    int ans=0;
    for(int i=0;i<cur;i++)
    {
        sort(no[i].begin(),no[i].end(),comp);
        sort(re[i].begin(),re[i].end(),comp);
        int x=min(no[i].size(),re[i].size());
        for (int j=0;j<x;j++)
        {
            if (no[i][j]+re[i][j]<0)
                break;
            ans1+=no[i][j]+re[i][j];
            max_even[i]=j+1;
        }
        sort(pal[i].begin(),pal[i].end(),comp);
        for (int j=0;j<pal[i].size();j+=2)
        {
            if (j+1<pal[i].size())
            {
                if (pal[i][j]+pal[i][j+1]<0)
                {
                    mx=max(mx,pal[i][j]);
                    break;
                }
                ans+=pal[i][j]+pal[i][j+1];
                max_even[i]=j+2;
            }
            else
                mx=max(mx,pal[i][j]);
        }

    }
    ans+=ans1/2;
    int yn=ans;
    for (int i=0;i<cur;i++)
    {
        if (pal[i].size())
        {
            if(max_even[i]>0)
                ans=max(ans,yn-pal[i][max_even[i]-1]);
            if (max_even[i]<pal[i].size())
                ans=max(ans,yn+pal[i][max_even[i]]);
        }
    }
    cout<<ans<<endl;
}