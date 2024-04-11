#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

char r[4]={'U','D','L','R'};
char a[5555][5555];
int n,m,x,y,s,p,u,ans1=0,ans2=0,v[5555],k;
vector<int> f[5555],d[4][5555];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d\n",&n,&m);
	for (int i=0;i<n;i++)f[i].resize(m+10);
	for (int i=0;i<n;i++)for (int j=0;j<4;j++)d[j][i].resize(m+10);
	for (int i=0;i<n;i++)gets(a[i]);
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)if (a[i][j]!='.'){
		for (int ii=0;ii<n;ii++)for (int jj=0;jj<m;jj++)f[ii][jj]=0;
		for (int ii=0;ii<n;ii++)for (int jj=0;jj<m;jj++)
		for (int o=0;o<4;o++)d[o][ii][jj]=1;
		x=i;
		y=j;
		s=0;
		while(x>=0&&x<n&&y>=0&&y<m){
			for (u=0;u<4;u++)if (r[u]==a[x][y])break;
			k=0;
			s++;
			f[x][y]=1;
			if (u==0){
				while (x>=0&&(a[x][y]=='.'||f[x][y])){
					v[k++]=x;
					x-=d[u][x][y];		
				}
				for (int l=0;l<k;l++)d[u][v[l]][y]=v[l]-x;
			}
			if (u==1){
				while (x<n&&(a[x][y]=='.'||f[x][y])){
					v[k++]=x;
					x+=d[u][x][y];		
				}
				for (int l=0;l<k;l++)d[u][v[l]][y]=x-v[l];
			}
			if (u==2){
				while (y>=0&&(a[x][y]=='.'||f[x][y])){
					v[k++]=y;
					y-=d[u][x][y];		
				}
				for (int l=0;l<k;l++)d[u][x][v[l]]=v[l]-y;
			}
			if (u==3){
				while (y<m&&(a[x][y]=='.'||f[x][y])){
					v[k++]=y;
					y+=d[u][x][y];		
				}
				for (int l=0;l<k;l++)d[u][x][v[l]]=y-v[l];
			}

		}		
		if (s>ans1){
			ans1=s;
			ans2=1;
		}else if (s==ans1)ans2++;
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}