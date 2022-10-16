#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];
int dp[N];
int len=0;
int type[N];
vector<int>layer[N];
int bins(int x,int y)
{
    int l=0,r=layer[x].size()-1;
    while(l<r)
	{
        int mid=(l+r)>>1;
        if(a[layer[x][mid]]>=y) l=mid+1;
        else r=mid;
    }
    return l;
}
void init()
{
	cin>>n;
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++)
	{
        cin>>a[i];
        int tmp_len=lower_bound(dp,dp+n+1,a[i])-dp;
        dp[tmp_len]=min(dp[tmp_len],a[i]);
        layer[tmp_len].push_back(i);
        len=max(len,tmp_len);
    }
    for(int i=1;i<=n;i++) type[i]=1;
    if(layer[len].size()==1) type[layer[len][0]]=3;
    else for(int i=0;i<layer[len].size();i++) type[layer[len][i]]=2;
}
void solve()
{
	for(int i=len;i>=2;i--)
	{
        for(int j=0;j<layer[i].size();j++)
		{
            int num=layer[i][j];
            if(type[num]>1)
			{
                int l=bins(i-1,a[num]);
                int r=lower_bound(layer[i-1].begin(),layer[i-1].end(),num)-layer[i-1].begin()-1;
                for(int k=l;k<=r;k++)type[layer[i-1][k]]=2;
            }
        }
        int cnt=0,ans=0;
        for(int j=0;j<layer[i-1].size();j++)
			if(type[layer[i-1][j]]==2)
			{
    	        cnt++;
    	        ans=j;
    	    }
        if(cnt==1)type[layer[i-1][ans]]=3;
    }
}
int main()
{
    init();
    solve();
    for(int i=1;i<=n;i++) cout<<type[i];
}