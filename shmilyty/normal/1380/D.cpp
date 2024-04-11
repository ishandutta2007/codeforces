#include<iostream>
#include<algorithm>
using namespace std;
int n,m,x,k,y,a[200010],b[200010];
long long ans=0;
bool mark[200010],flag=1;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>x>>k>>y;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=1,j=1;i<=n;i++)
		if(a[i]==b[j])
		{
			j++,mark[i]=1;
			if(j>m)
			{
				flag=0;
				break;
			}
		}
	if(flag)
	{
		cout<<-1<<endl;
		return 0;
	}
	mark[n+1]=1;
	for(int i=1,last=0,maxx=0;i<=n+1;i++)
	{
		if(mark[i])
		{
			int cnt=i-last-1;
			if(cnt<k)
			{
				if(maxx<max(a[last],a[i]))
					ans+=(long long)cnt*y;
				else
				{
					cout<<-1<<endl;
					return 0;
				}
			}
			else
			{
				if(x>y*k)
				{
					if(maxx<max(a[last],a[i]))
						ans+=(long long)cnt*y;
					else
						ans+=(long long)(cnt-k)*y+x;
				}
				else
					ans+=(long long)(cnt%k)*y+(long long)(cnt/k)*x;
			}
			last=i,maxx=0;
		}
		else
			maxx=max(maxx,a[i]);
	}
	cout<<ans<<endl;
	return 0;
}