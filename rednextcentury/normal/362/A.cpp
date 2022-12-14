#include <iostream>
#include <map>
# include <stdio.h>
# include <queue>
using namespace std;
int c[]={2,-2};
void bfs (int x,int y,int dist[][9])
{
	queue<int>q1;
	queue<int>q2;
	bool visited [9][9]={0};
	q1.push(x);
	q2.push(y);
	visited[x][y]=1;
	dist[x][y]=1;
	while(!q1.empty())
	{
		int h=q1.front();
		int w=q2.front();
		q1.pop();
		q2.pop();
		for (int i=0;i<2;i++)
		{
			for (int g=0;g<2;g++)
			{
				if (h+c[i]<8 && w+c[g]<8 && h+c[i]>=0 && w+c[g]>=0 && visited[h+c[i]][w+c[g]]==0)
				{
					visited[h+c[i]][w+c[g]]=1;
					dist[h+c[i]][w+c[g]]=dist[h][w]+1;
					q1.push(h+c[i]);
					q2.push(w+c[g]);
				}
			}
		}
	}
}
int bfs2 (int x,int y,int dist[][9],int dist2[][9],char a[][9])
{
	queue<int>q1;
	queue<int>q2;
	int ans=0;
	bool visited [9][9]={0};
	q1.push(x);
	q2.push(y);
	visited[x][y]=1;
	dist2[x][y]=1;
	while(!q1.empty())
	{
		int h=q1.front();
		int w=q2.front();
		q1.pop();
		q2.pop();
		for (int i=0;i<2;i++)
		{
			for (int g=0;g<2;g++)
			{
				if (h+c[i]<8 && w+c[g]<8 && h+c[i]>=0 && w+c[g]>=0 && visited[h+c[i]][w+c[g]]==0)
				{
					visited[h+c[i]][w+c[g]]=1;
					dist2[h+c[i]][w+c[g]]=dist2[h][w]+1;
					if (dist2[h+c[i]][w+c[g]]%2==dist[h+c[i]][w+c[g]]%2 && a[h+c[i]][w+c[g]]!='#' && dist[h+c[i]][w+c[g]]!=0 && dist2[h+c[i]][w+c[g]]!=0)
					{
						ans++;
						return 1;
					}
					q1.push(h+c[i]);
					q2.push(w+c[g]);
				}
			}
		}
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	for (int i=0;i<t;i++)
	{
		char a[9][9]={0};
		int dist[9][9]={0};
		int dist2[9][9]={0};
		int x1=100,x2,y1,y2;
		for (int i=0;i<8;i++)
		{
			for (int x=0;x<8;x++)
			{
				cin>>a[i][x];
				if (a[i][x]=='K' && x1==100)
				{
					x1=i;
					y1=x;
				}
				else if (a[i][x]=='K' && x1!=100)
				{
					x2=i;
					y2=x;
				}
				
				
			}
		}
		bfs(x1,y1,dist);
				if(bfs2(x2,y2,dist,dist2,a)==1)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
	}
}