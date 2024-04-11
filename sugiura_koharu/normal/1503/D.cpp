#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
pair <int,int> a[400005];
int pos[400005],vis[400005],A[400005],B[400005],l,r,mx,mn,ans,bel[400005],c[400005];
int wx[400005],wy[400005];
priority_queue <int> q1;
priority_queue <int,vector <int>,greater<int> >q2;
queue <int> q;
int n;
const int qwq=200001;
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n*2;i++) q1.push(i),q2.push(i);
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].first >> a[i].second;
		pos[a[i].first]=pos[a[i].second]=i;
	}
	l=1,r=n;
	for(int i=1;i<=n*2;i++)
	{
		if(!vis[i])
		{
			q.push(i),q.push(a[pos[i]].first^a[pos[i]].second^i);
			vis[i]=vis[a[pos[i]].first^a[pos[i]].second^i]=1;
			bel[i]=l,bel[a[pos[i]].first^a[pos[i]].second^i]=l+qwq;
			l++;
		}
		while(!q.empty())
		{
			int x=q.front(),y=a[pos[x]].first^a[pos[x]].second^x;
			q.pop();
			c[x]=c[y]=i;
			while(!q2.empty()&&q2.top()<=x&&x<y)
			{
				int t=q2.top();
				q2.pop();
				if(vis[t]) continue;
				q.push(t),q.push(a[pos[t]].first^a[pos[t]].second^t);
				vis[t]=vis[a[pos[t]].first^a[pos[t]].second^t]=1;
				if(bel[x]<=l)
				{
					bel[t]=r+qwq,bel[a[pos[t]].first^a[pos[t]].second^t]=r;
					--r;
				}
				else
				{
					bel[t]=l,bel[a[pos[t]].first^a[pos[t]].second^t]=l+qwq;
					l++;
				}
			}
			while(!q1.empty()&&q1.top()>=x&&x>y)
			{
				int t=q1.top();
				q1.pop();
				if(vis[t]) continue;
				q.push(t),q.push(a[pos[t]].first^a[pos[t]].second^t);
				vis[t]=vis[a[pos[t]].first^a[pos[t]].second^t]=1;
				if(bel[x]<=qwq)
				{
					bel[t]=l+qwq,bel[a[pos[t]].first^a[pos[t]].second^t]=l;
					++l;
				}
				else
				{
					bel[t]=r,bel[a[pos[t]].first^a[pos[t]].second^t]=r+qwq;
					--r;
				}
			}
		}
	}
	for(int i=1;i<=n+n;i++)
	{
		if(bel[i]<=qwq) A[bel[i]]=i;
		else B[bel[i]-qwq]=i;
		if(!bel[i]) return 1;
	}
	int flag=1;
	for(int i=2;i<=n;i++)
		if(A[i]<A[i-1]) flag=0;
	for(int i=2;i<=n;i++)
		if(B[i]>B[i-1]) flag=0;
	if(!flag)
	{
		cout << -1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(bel[a[i].first]<=qwq) ++wx[c[a[i].first]];
		else ++wy[c[a[i].first]];
	}
	for(int i=1;i<=n+n;i++)
		ans+=min(wx[i],wy[i]);
	cout << ans;
	return 0;
}