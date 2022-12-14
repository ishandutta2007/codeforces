#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int> pal_array(string s)
{
    int n = s.size();
    s = "@" + s + "$";
    vector<int> len(n + 1);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++)
    {
        len[i] = min(r - i, len[l + (r - i)]);
        while(s[i - len[i]] == s[i + len[i]])
            len[i]++;
        if(i + len[i] > r)
        {
            l = i - len[i];
            r = i + len[i];
        }
    }
    len.erase(len.begin());
    return len;
}
vector<int> ret;
bool is_pal(int l,int r)
{
    l=l*2+1;
    r=r*2+1;
    int mid=(l+r)/2;
    if (ret[mid]+mid-1>=r && mid-ret[mid]+1<=l)
        return 1;
    return 0;
}
int dp[5000001];
int cnt(int l,int r)
{
    if (r<l || !is_pal(l,r)) return 0;
    if (dp[r]!=-1) return dp[r];
    return dp[r]=1+cnt(l,l+(r-l+1)/2-1);
}
char fast[6000000];
int main()
{
    scanf("%s",fast);
    string s;
    s=fast;
    memset(dp,-1,sizeof(dp));
    cin>>s;
    string tmp="|";
    for (int i=0;i<s.size();i++)
        tmp+=s[i],tmp+="|";
    ret = pal_array(tmp);
    int ans=0;
    for (int i=0;i<s.size();i++)
        ans+=cnt(0,i);
    cout<<ans<<endl;
}