#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define MAX 51
int a,x,y,R,C,sr,sc,fr,fc,idx,k;
char grid[MAX][MAX];
bool visit[MAX][MAX];
bool visited[MAX][MAX];
pair<int,pair<int,int> >lake[MAX*MAX];
bool inside(int r,int c){
	return 0<=r && r<R && 0<=c && c<C;
}
void DFS(int r,int c){
	if(!inside(r,c))return;
	if(grid[r][c]=='*')return;
	if(visit[r][c]==1)return; 
	
	visit[r][c]=1;
	visited[r][c]=1;
	DFS(r+1,c); //bergerak ke bawah
 	DFS(r-1,c); //bergerak ke atas
 	DFS(r,c+1); //bergerak ke kanan
 	DFS(r,c-1); //bergerak ke kiri 
}
void DFSa(int r,int c){
	if(!inside(r,c))return;
	if(grid[r][c]=='*')return;
	
	grid[r][c]='*';
	DFSa(r+1,c); //bergerak ke bawah
 	DFSa(r-1,c); //bergerak ke atas
 	DFSa(r,c+1); //bergerak ke kanan
 	DFSa(r,c-1); //bergerak ke kiri 
}
int main(){
	cin>>R>>C>>k;
	rep(r,R){
		rep(c,C)cin>>grid[r][c];
	}
	rep(i,R){
		DFS(i,0);
		DFS(i,C-1);
	}
	rep(i,C){
		DFS(0,i);
		DFS(R-1,i);
	}
	rep(i,R){
		rep(j,C){
			if(visit[i][j]==0 && grid[i][j]!='*'){
				memset(visited,false,sizeof(visited));
				x=0;
				DFS(i,j);
				rep(r,R){
					rep(c,C){
						if(visited[r][c]==1)x++; //buat itung DFS per block
					}
				}
				lake[idx]=make_pair(x,make_pair(i,j));
				idx++;
			}
		}
	}
	//cout<<idx<<endl;
	sort(lake,lake+idx);
	y=idx-k;
	rep(i,y){
		sr=lake[i].second.first;
		sc=lake[i].second.second;
		//cout<<sr<<" "<<sc<<endl;
		DFSa(sr,sc);
		fr+=lake[i].first;
	}
	//cout<<endl;
	//rep(r,R){
	//	rep(c,C)cout<<visit[r][c]<<" "; //buat cek visit udh bener apa kgk :v
	//	cout<<endl;
	//}
	cout<<fr<<endl;
	rep(r,R){
		rep(c,C)cout<<grid[r][c];
		cout<<endl;
	}
	return 0;
}