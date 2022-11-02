#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
unsigned int grid1[500][500][16],grid2[500][500][16];
inline void insert(unsigned int grid[][500][16],int x,int y,int bit){
	grid[x][y][bit>>5]^=((unsigned int)1)<<(bit&31);
}
inline bool query(unsigned int grid[][500][16],int x,int y,int bit){
	return (grid[x][y][bit>>5]>>(y&31))&((unsigned int)1);
}
struct Point{
	long long x,y;
	void scan(){cin>>x>>y;}
}a[500],b[500];
bool cp( Point aa, Point bb ) { return aa.x!=bb.x?aa.x<bb.x:aa.y<bb.y; }
int main(){
	int i,j,k,N,M,an=0;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)a[i].scan();
	for(i=0;i<M;i++)b[i].scan();
	sort(a,a+N,cp);
	sort(b,b+M,cp);
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++){
			long long tx=a[j].x-a[i].x;
			long long ty=a[j].y-a[i].y;
			for(k=0;k<M;k++){
				if(tx*(b[k].y-a[i].y)>ty*(b[k].x-a[i].x)){
					insert(grid1,i,j,k);
				}
				else{
					insert(grid2,i,j,k);
				}
			}
		}
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++) {
			long long tx=a[j].x-a[i].x;
			long long ty=a[j].y-a[i].y;
			for(k=j+1;k<N;k++){
				if(tx*(a[k].y-a[i].y)>ty*(a[k].x-a[i].x)){
					if((grid1[i][j][0]&grid1[j][k][0]&grid2[i][k][0])||
							(grid1[i][j][1]&grid1[j][k][1]&grid2[i][k][1])||
							(grid1[i][j][2]&grid1[j][k][2]&grid2[i][k][2])||
							(grid1[i][j][3]&grid1[j][k][3]&grid2[i][k][3])||
							(grid1[i][j][4]&grid1[j][k][4]&grid2[i][k][4])||
							(grid1[i][j][5]&grid1[j][k][5]&grid2[i][k][5])||
							(grid1[i][j][6]&grid1[j][k][6]&grid2[i][k][6])||
							(grid1[i][j][7]&grid1[j][k][7]&grid2[i][k][7])||
							(grid1[i][j][8]&grid1[j][k][8]&grid2[i][k][8])||
							(grid1[i][j][9]&grid1[j][k][9]&grid2[i][k][9])||
							(grid1[i][j][10]&grid1[j][k][10]&grid2[i][k][10])||
							(grid1[i][j][11]&grid1[j][k][11]&grid2[i][k][11])||
							(grid1[i][j][12]&grid1[j][k][12]&grid2[i][k][12])||
							(grid1[i][j][13]&grid1[j][k][13]&grid2[i][k][13])||
							(grid1[i][j][14]&grid1[j][k][14]&grid2[i][k][14])||
							(grid1[i][j][15]&grid1[j][k][15]&grid2[i][k][15])
					  );
					else an++;
				}
				else{
					if((grid2[i][j][0]&grid2[j][k][0]&grid1[i][k][0])||
							(grid2[i][j][1]&grid2[j][k][1]&grid1[i][k][1])||
							(grid2[i][j][2]&grid2[j][k][2]&grid1[i][k][2])||
							(grid2[i][j][3]&grid2[j][k][3]&grid1[i][k][3])||
							(grid2[i][j][4]&grid2[j][k][4]&grid1[i][k][4])||
							(grid2[i][j][5]&grid2[j][k][5]&grid1[i][k][5])||
							(grid2[i][j][6]&grid2[j][k][6]&grid1[i][k][6])||
							(grid2[i][j][7]&grid2[j][k][7]&grid1[i][k][7])||
							(grid2[i][j][8]&grid2[j][k][8]&grid1[i][k][8])||
							(grid2[i][j][9]&grid2[j][k][9]&grid1[i][k][9])||
							(grid2[i][j][10]&grid2[j][k][10]&grid1[i][k][10])||
							(grid2[i][j][11]&grid2[j][k][11]&grid1[i][k][11])||
							(grid2[i][j][12]&grid2[j][k][12]&grid1[i][k][12])||
							(grid2[i][j][13]&grid2[j][k][13]&grid1[i][k][13])||
							(grid2[i][j][14]&grid2[j][k][14]&grid1[i][k][14])||
							(grid2[i][j][15]&grid2[j][k][15]&grid1[i][k][15])
					  );
					else an++;

				}
			}
		}
	cout<<an<<endl;
	return 0;
}