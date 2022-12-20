#include<bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define pll pair<ll,ll>
using namespace std;
char a[110][110];
int main()
{
	ll n,m;cin>>n>>m;
	ll dpr=m+1,dpl=0;
	bool checked=0;
	for(ll i=n-1;i>=0;i--)
	{
		bool any=0;
		for(ll j=0;j<m+2;j++)
		{
		cin>>a[i][j];
		if(a[i][j]=='1')any=1;
		}
		if(!any&&!checked)n--;
		else checked=1;
	}
	for(ll i=0;i<n;i++)
	{
		ll first=0,last=m+1;
		while(first<m+2&&a[i][first]!='1')first++;
		if(first==m+2)first=0;
		while(last>=0&&a[i][last]!='1')last--;
		if(last==-1)last=m+1;
		ll Dr,Dl;
		if(i==n-1) {Dr=dpr+m+1-(a[i][first]=='1'?first:m+1),Dl=dpl+(a[i][last]=='1'?last:0);}
		else {Dr=min(dpr+2*(m+1-(a[i][first]=='1'?first:m+1))+1,dpl+m+2),Dl=min(dpl+2*(a[i][last]=='1'?last:0)+1,dpr+m+2);}
		dpr=Dr;dpl=Dl;
	}
	cout<<min(dpr,dpl);
}