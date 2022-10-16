#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[555][555],r[555],c[555],wr[111111],wc[111111];
pair<int,int> pos[111111];
int ans[555][555];
vector<int> R,C,both;
queue<pair<int,int> > q;
int vis[555][555];
int L;
inline bool ok(int x,int y)
{
	if(x<1||x>n||y<1||y>m||vis[x][y]||ans[x][y])return false;
	if(x>=L&&y>=L)
	{
		if(ans[x-1][y]&&ans[x][y-1])
		{
			vis[x][y]=1;
			return true;
		}
		else return false;
	}
	else if(x<y)
	{
		if(ans[x+1][y]&&ans[x][y-1])
		{
			vis[x][y]=1;
			return true;
		}
		else return false;
	}
	else
	{
		if(ans[x-1][y]&&ans[x][y+1])
		{
			vis[x][y]=1;
			return true;
		}
		else return false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			r[i]=max(r[i],a[i][j]);
			c[j]=max(c[j],a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)wr[r[i]]=1;
	for(int i=1;i<=m;i++)wc[c[i]]=1;
	for(int i=n*m;i>=1;i--)
	{
		if(wr[i]&&wc[i])both.push_back(i);
		else if(wr[i])R.push_back(i);
		else if(wc[i])C.push_back(i);
	}
	L=both.size();
	for(int i=1;i<=L;i++)
	{
		pos[both[L-i]]={i,i};
	}
	for(int i=0;i<R.size();i++)
	{
		pos[R[i]]={L+i+1,L};
	}
	for(int i=0;i<C.size();i++)
	{
		pos[C[i]]={L,L+i+1};
	}
	for(int i=n*m;i>=1;i--)
	{
		int x,y;
		if(wr[i]||wc[i])
		{
			x=pos[i].first,y=pos[i].second;
			ans[x][y]=i;
		}
		else
		{
			assert(!q.empty());
			auto _=q.front();q.pop();
			x=_.first,y=_.second;
			ans[x][y]=i;
		}
		if(ok(x+1,y))q.push({x+1,y});
		if(ok(x-1,y))q.push({x-1,y});
		if(ok(x,y+1))q.push({x,y+1});
		if(ok(x,y-1))q.push({x,y-1});
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}