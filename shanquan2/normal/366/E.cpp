#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

pair<int,int> best[9][4];
int dis[9][9];
int main(){
	int n,m,k,s;
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int i=0;i<9;i++)
		for(int j=0;j<4;j++)
			best[i][j]=make_pair(10000,10000);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			int x;
			scanf("%d",&x);x--;
			if(i+j<abs(best[x][0].first)+abs(best[x][0].second)){
				best[x][0].first=i;
				best[x][0].second=j;
			}
			if(i+(m-1-j)<abs(best[x][1].first)+abs(m-1-best[x][1].second)){
				best[x][1].first=i;
				best[x][1].second=j;
			}
			if((n-1-i)+j<abs(n-1-best[x][2].first)+abs(best[x][2].second)){
				best[x][2].first=i;
				best[x][2].second=j;
			}
			if((n-1-i)+(m-1-j)<abs(n-1-best[x][3].first)+abs(m-1-best[x][3].second)){
				best[x][3].first=i;
				best[x][3].second=j;
			}
		}
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++){
			dis[i][j]=0;
			for(int p=0;p<4;p++)
				for(int q=0;q<4;q++)
					if(dis[i][j]<abs(best[i][p].first-best[j][q].first)+abs(best[i][p].second-best[j][q].second))
						dis[i][j]=abs(best[i][p].first-best[j][q].first)+abs(best[i][p].second-best[j][q].second);
		}
/*	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++)
			printf("%d ",dis[i][j]);
		printf("\n");
	}*/
	int ans=0;
	int x;
	scanf("%d",&x);x--;
	for(int i=1;i<s;i++){
		int y;scanf("%d",&y);y--;
		ans=max(ans,dis[x][y]);
		x=y;
	}
	printf("%d\n",ans);
	return 0;
}