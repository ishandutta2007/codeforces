#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const int N=50;
int n,m,Q;
string a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	int i,w,x,y;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	cin>>Q;
	while(Q--)
	{
		cin>>w;
		x=(w-1)%n+1;y=(w-1)%m+1;
		cout<<(a[x]+b[y])<<endl;
	}
	return 0;
}