#include<bits/stdc++.h>

using namespace std;

struct edge
{
	int from,to,w;
};

int dp[300001];
edge e[300001];

bool cmp(edge a,edge b)
{
	return a.w>b.w;
}

vector<edge> v[100001];
vector<pair<int,int> > curr;

int main ()
{
	int n,m,i,cnt=0,res=0,j;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;

	for(i=0;i<m;i++)
    {
        cin>>e[i].from>>e[i].to>>e[i].w;
        v[e[i].w].push_back(e[i]);
    }

	for(i=0;i<=100000;i++)
	{
	    curr.clear();

		for(j=0;j<v[i].size();j++)
            curr.push_back(make_pair(v[i][j].to,max(dp[v[i][j].to],dp[v[i][j].from]+1)));

        for(j=0;j<curr.size();j++)
        {
            dp[curr[j].first]=max(curr[j].second,dp[curr[j].first]);
            res=max(res,curr[j].second);
        }
	}

	cout<<res<<"\n";

	return 0;
}