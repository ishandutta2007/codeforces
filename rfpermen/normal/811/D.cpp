#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int X,Y,row,col,nxcol,nxrow,frow,fcol,srow,scol,idx,n,R,L,U,D;
const int INF=1e9;
char grid[105][105],move;
int shortest[105][105];
pair<int,int> prev[105][105];
const int dr[4]={1,0,-1,0};
const int dc[4]={0,1,0,-1};
bool inside(int x,int y){
	return x>0 && y>0 && y<=Y && x<=X;
}
queue<pair<int,int> > q;
int main(){
	cin>>X>>Y;
	rep(r,1,X){
		rep(c,1,Y){
			shortest[r][c]=-1;
			cin>>grid[r][c];
			if(grid[r][c]=='F')frow=r, fcol=c;
		}
	}
	row=1, col=1;
	if(grid[row][col+1]!='*'){
		cout<<"R"<<endl;
		cin>>nxrow>>nxcol;
		if(nxrow==frow && nxcol==fcol){
			return 0;
		}
		if(nxcol==col+1){
			R=1, L=-1;
			cout<<"L"<<endl;
			cin>>nxrow>>nxcol;
		}
		else R=-1, L=1;
	}
	if(grid[row+1][col]!='*'){
		cout<<"D"<<endl;
		cin>>nxrow>>nxcol;
		if(nxrow==frow && nxcol==fcol)return 0;
		if(nxrow==row+1)D=1, U=-1;
		else D=-1, U=1;
		row=nxrow;
	}
	if(R!=0 && D==0){
		while(grid[row+1][col]=='*'){
			if(R==1){
				cout<<"R"<<endl;
				cin>>nxrow>>nxcol;
				if(nxrow==frow && nxcol==fcol)return 0;
			}else {
				cout<<"L"<<endl;
				cin>>nxrow>>nxcol;
				if(nxrow==frow && nxcol==fcol)return 0;
			}
			col++;
		}
		cout<<"D"<<endl;
		cin>>nxrow>>nxcol;
		if(nxrow==frow && nxcol==fcol)return 0;
		if(nxrow==row+1)D=1, U=-1;
		else D=-1, U=1;
		row=nxrow;
	}else if(R==0 && D!=0){
		while(grid[row][col+1]=='*'){
			if(D==1){
				cout<<"D"<<endl;
				cin>>nxrow>>nxcol;
				if(nxrow==frow && nxcol==fcol)return 0;
			}else {
				cout<<"U"<<endl;
				cin>>nxrow>>nxcol;
				if(nxrow==frow && nxcol==fcol)return 0;
			}
			row++;
		}
		cout<<"R"<<endl;
		cin>>nxrow>>nxcol;
		if(nxrow==frow && nxcol==fcol)return 0;
		if(nxcol==col+1)R=1, L=-1;
		else R=-1, L=1;
		col=nxcol;
	}
	srow=row, scol=col;
	shortest[frow][fcol]=0;
	q.push(mp(frow,fcol));
	
		while(!q.empty()){
		pair<int,int> cur = q.front();
		q.pop();
		
		row=cur.fi;
		col=cur.se;
		
		rep(i,0,3){
			nxrow=row+dr[i];
			nxcol=col+dc[i];
			
			if(!inside(nxrow,nxcol))continue;
			if(grid[nxrow][nxcol]=='*')continue;
			if(shortest[nxrow][nxcol]!=-1)continue;
			
			//prev[nxrow][nxcol]= mp(row,col);
			shortest[nxrow][nxcol]= shortest[row][col]+1;
			q.push(mp(nxrow,nxcol));
		}
	}
	//rep(r,1,X){
	//	rep(c,1,Y)cout<<shortest[r][c];
	//	cout<<endl;
	//}
	row=srow, col=scol;
	while(row!=frow || col!=fcol){
		rep(i,0,3){
			nxrow=row+dr[i];
			nxcol=col+dc[i];
			if(!inside(nxrow,nxcol))continue;
			if(shortest[nxrow][nxcol]!=shortest[row][col]-1)continue;
			else {
				if(i==0){
					if(D==1)cout<<"D"<<endl;
					else cout<<"U"<<endl;
				}
				else if(i==1){
					if(R==1)cout<<"R"<<endl;
					else cout<<"L"<<endl;
				}
				else if(i==2){
					if(D==-1)cout<<"D"<<endl;
					else cout<<"U"<<endl;
				}
				else if(i==3){
					if(R==-1)cout<<"R"<<endl;
					else cout<<"L"<<endl;
				}
				//cout<<nxrow<<" "<<nxcol<<endl;
				//cout<<i<< " "<<shortest[nxrow][nxcol]<<" "<<shortest[row][col]<<endl;
				cin>>row>>col;
				break;
			}
		}
	}
	return 0;
}