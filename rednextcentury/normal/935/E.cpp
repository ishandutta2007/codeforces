#include <bits/stdc++.h>
using namespace std;
#define ll long long
int neg;
int pos;
int op[1000000];
pair<int,int> dp[10001][101];
bool vis[10001][101];
string s;
pair<int,int> solve(int l,int r,int x)
{
    if (x<0)return {1e9,-1e9};
    if (isdigit(s[l]) && isdigit(s[r]))
    {
        if (neg)
        {
            if (x==0)
                return {s[l]-'0'+s[r]-'0',s[l]-'0'+s[r]-'0'};
            else if (x==1)
                return {s[l]-'0'-(s[r]-'0'),s[l]-'0'-(s[r]-'0')};
            else
                return {1e9,-1e9};
        }
        else
        {
            if (x==0)
                return {s[l]-'0'-(s[r]-'0'),s[l]-'0'-(s[r]-'0')};
            else if (x==1)
                return {s[l]-'0'+s[r]-'0',s[l]-'0'+s[r]-'0'};
            else
                return {1e9,-1e9};
        }
    }
    pair<int,int> &ret=dp[l][x];
    if (vis[l][x])
        return ret;
    vis[l][x]=1;
    ret.first = 1e9;
    ret.second=-1e9;
    if (isdigit(s[l]))
    {
        ret.first = min(ret.first,s[l]-'0'-solve(op[r]+1,r-1,x-neg).second);
        ret.first = min(ret.first,s[l]-'0'+solve(op[r]+1,r-1,x-pos).first);

        ret.second = max(ret.second,s[l]-'0'-solve(op[r]+1,r-1,x-neg).first);
        ret.second = max(ret.second,s[l]-'0'+solve(op[r]+1,r-1,x-pos).second);
    }
    else if (isdigit(s[r]))
    {
        ret.first = min(ret.first,solve(l+1,op[l]-1,x-neg).first-(s[r]-'0'));
        ret.first = min(ret.first,solve(l+1,op[l]-1,x-pos).first+(s[r]-'0'));

        ret.second = max(ret.second,solve(l+1,op[l]-1,x-neg).second-(s[r]-'0'));
        ret.second = max(ret.second,solve(l+1,op[l]-1,x-pos).second+(s[r]-'0'));
    }
    else
    {
        for (int j=0;j<=x;j++)
        {
            ret.first=min(ret.first,solve(l+1,op[l]-1,j-neg).first - solve(op[r]+1,r-1,x-j).second);
            ret.first=min(ret.first,solve(l+1,op[l]-1,j-pos).first + solve(op[r]+1,r-1,x-j).first);

            ret.second=max(ret.second,solve(l+1,op[l]-1,j-neg).second - solve(op[r]+1,r-1,x-j).first);
            ret.second=max(ret.second,solve(l+1,op[l]-1,j-pos).second + solve(op[r]+1,r-1,x-j).second);
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //memset(dp,-1,sizeof(dp));
    cin>>s;
    int p,m;
    cin>>p>>m;
    stack<int> st;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='(')
            st.push(i);
        else if (s[i]==')')
        {
            op[i]=st.top();
            op[st.top()]=i;
            st.pop();
        }
    }
    if (s.size()==1)
    {
        cout<<s<<endl;
        return 0;
    }
    if (p<m)
    {
        neg=0;
        pos=1;
        cout<<solve(1,s.size()-2,p).second<<endl;
        return 0;
    }
    else
    {
        neg=1;
        pos=0;
        cout<<solve(1,s.size()-2,m).second<<endl;
        return 0;
    }
}