#include<bits/stdc++.h>
#define MAXN 200005
#define INF 10000
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
int n,x,l,r,c;
vector<pair<int,pair<int,ll> > > a;
vector<pair<int,int> >minval[MAXN];
int main()
{
    scanf("%d %d",&n,&x);
    for(int i=0;i<n;i++)
    {
        cin>>l>>r>>c;
		a.pb({l,{r,c}});
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
	{
		int l=a[i].first,r=a[i].second.first,c=a[i].second.second;
		int d=r-l+1;
		minval[d].pb({l,c});
	}
	for(int i=0;i<n;i++)
	{
		for(int j=minval[i].size()-2;j>=0;j--)
		{
			minval[i][j].second=min(minval[i][j].second,minval[i][j+1].second);
		}
	}
	ll res=1e18;
	for(int i=0;i<n;i++)
	{
		int curr_val = a[i].second.first - a[i].first +1;
		ll curr_cost = a[i].second.second;
		int need = x - curr_val;
		if(need<0 or minval[need].size()==0)
			continue;
		int curr_right = a[i].second.first;
		int low = 0 ,high = minval[need].size()-1,ind=-1;
		while(low<=high)
		{
			int mid  = (low+high)/2;
			if(minval[need][mid].first>curr_right)
			{
				ind=mid;
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		if(ind==-1)
		{
			continue;
		}
		else
		{
			res=min(res,curr_cost + minval[need][ind].second);
		}
	}
	if(res==1e18)
		cout<<-1<<endl;
	else
		cout<<res<<endl;
	return 0;
}