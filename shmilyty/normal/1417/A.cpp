#include<bits/stdc++.h>
using namespace std;
int t,n,k,ans;
priority_queue<int> q;
int main() 
{
	scanf("%d",&t);
	while(t--)
	{
		while(!q.empty())
			q.pop();
		ans=0;
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			q.push(-a);	
		} 
		int a,b;
		while(1)
		{
			a=q.top();
			q.pop();
			b=q.top();
			q.pop();
			b+=a;
			if(-b>k)
				break;
			ans++;
			q.push(a);
			q.push(b);
		}
		cout<<ans<<endl;
	}
	return 0;
}