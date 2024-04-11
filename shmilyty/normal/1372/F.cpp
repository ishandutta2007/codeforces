#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
pair<int,int> ask(int l,int r)
{
	cout<<"? "<<l<<" "<<r<<endl;
	int x,f;
	scanf("%d%d",&x,&f);
	return make_pair(x,f);
}
void solve(int l,int r)
{
	if(l>r)	
		return ;
	pair<int,int> p=ask(l,r);
	int ll=r-p.second+1;
	int rr=l+p.second-1;
	if(ll<=rr)
	{
		for(int i=ll;i<=rr;i++)
			a[i]=p.first;
		solve(l,ll-1);
		solve(rr+1,r);
	}
	else
	{
		int mid=(l+r)>>1;
		solve(l,mid);
		solve(mid+1,r);
	}
}
int main()
{
	scanf("%d",&n);
	solve(1,n);
	cout<<"! ";
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}