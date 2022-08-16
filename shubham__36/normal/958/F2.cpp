#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define v vector<ll>
#define vv vector<v>
#define MAX 15000001
#define vs vector<string> 
ll m;
ll combine(ll a,ll b)
{
    return min(a,b);
}
void update(ll pos,ll value,v &tree)
{
    pos+=m-1;
    tree[pos]=value;
    pos=pos/2;
    while (pos>=1)
    {
        tree[pos]=combine(tree[2*pos],tree[2*pos+1]);
        pos=pos/2;
    }
}
ll query(ll l,ll r, v&tree)
{
    l+=m-1;
    r+=m-1;
    ll ans=1e9;
    while (l<=r)
    {
        if (l%2==1)
        {
            ans=combine(ans,tree[l]);
            l++;
        }
        if (r%2==0)
        {
            ans=combine(ans,tree[r]);
            r--;
        }
        l=l/2;
        r=r/2;
    }
    return ans;
}
int main() 
{
	int n;
	cin>>n>>m;
	v arr(n+1);
	for (ll i=1; i<=n; i++)
		cin>>arr[i];
	v b(m+1,0);
	ll sum=0;
	for (ll i=1; i<=m; i++)
	{
		cin>>b[i];
		sum+=b[i];
	}
	v count(m+1,0);
	for (ll i=1; i<=n; i++)
		count[arr[i]]++;
	for (ll i=1; i<=m; i++)
	{
		if (count[i]<b[i])
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	v maxi(2*m+10,-1e9);
	vv colors(m+1);
	ll ans=2e9;
	for (int i=1; i<=m; i++)
	{
		if (b[i]==0)
			update(i,2e9,maxi);
	}
	for (int i=1; i<=n; i++)
	{
		colors[arr[i]].push_back(i);
		if (colors[arr[i]].size()>=b[arr[i]])
		{
			int y=colors[arr[i]].size();
			if (b[arr[i]]==0)
			{
				update(arr[i],2e9,maxi);
			}
			else
			{
				int x=colors[arr[i]][y-b[arr[i]]];
				update(arr[i],x,maxi);
			}
		}
		ll temp=query(1,m,maxi);
		ans=min(ans,i-temp+1);
		//cout<<ans<<" "<<temp<<endl;
	}
	//cout<<ans<<endl;
	if (ans<1e8)
	{
		cout<<ans-sum<<endl;
	}
	else
		cout<<-1<<endl;
    return 0; 
}