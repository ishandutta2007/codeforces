#include<bits/stdc++.h>
#include<windows.h>
#define N 102
#define pb push_back
using namespace std;
int n,k,mp[4][N],lx,ly,tx,ty,now,mx[3][N],my[3][N];
struct dat
{int i,x,y;};
vector<dat>ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<4;i++)
	for(int j=0;j<n;j++)
	scanf("%d",mp[i]+j);
	for(int i=0;i<n;i++)
	{
		if(mp[1][i]==mp[0][i]&&mp[1][i])
		ans.pb({mp[1][i],0,i}),
		mp[1][i]=0,k--;
		if(mp[2][i]==mp[3][i]&&mp[2][i])
		ans.pb({mp[2][i],3,i}),
		mp[2][i]=0,k--;
	}
	lx=-1;
	for(int i=1;i<3;i++)
	for(int j=0;j<n;j++)
	if(!mp[i][j]){lx=i,ly=j;break;}
	if(lx<0)return puts("-1"),0;
	for(int i=0;i<n;i++)
	my[1][i]=1,my[2][i]=-1;
	my[2][0]=0,mx[2][0]=-1;
	my[1][n-1]=0,mx[1][n-1]=1;
	for(;k;)
	{
		//cerr<<lx<<','<<ly<<'('<<k<<endl;
		//Sleep(500);
		tx=lx+mx[lx][ly],ty=ly+my[lx][ly];
		//cerr<<ly<<"???\n";
		if(now=mp[tx][ty])
		{
			ans.pb({now,lx,ly});
			//cerr<<mp[3][1]<<' '<<ly<<endl;
			//cerr<<now<<"?"<<mp[3][ly]<<endl;
			swap(mp[lx][ly],mp[tx][ty]);
			if(lx==1&&mp[0][ly]==now)
			{
				ans.pb({now,0,ly}),mp[lx][ly]=0;
				k--;
			}
			else if(lx==2&&mp[3][ly]==now)
			{
				ans.pb({now,3,ly}),mp[lx][ly]=0;
				k--;
			}
		}
		lx=tx,ly=ty;
	}
	printf("%d\n",ans.size());
	for(auto i:ans)
	printf("%d %d %d\n",i.i,i.x+1,i.y+1);
}