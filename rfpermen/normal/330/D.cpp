#include<bits/stdc++.h>
#define clr clear()
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int INF=1e9;
using namespace std;
int R,C,frow,fcol,row,col,srow,scol,nxcol,nxrow;
int ans,intest[1005][1005],goal;
char grid[1005][1005];
queue<pair<int,int> > q;
const int dr[4] = {-1,0,1,0};
const int dc[4] = {0,-1,0,1};
bool inside(int r,int c){
	return r>0 && c>0 && r<=R && c<=C;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>R>>C;
	rep(r,1,R){
		rep(c,1,C){
			cin>>grid[r][c];
			intest[r][c]=INF;
			if(grid[r][c]=='S')srow=r, scol=c;
			else if(grid[r][c]=='E')frow=r, fcol=c;
		}
	}
	intest[frow][fcol]=0;
	q.push(mp(frow,fcol));
	while(!q.empty()){
		pair<int,int> cur = q.front();
		q.pop();
		
		row = cur.fi;
		col = cur.se;
		//cout<<row<<" "<<col<<endl;
		rep(i,0,3){
			nxrow= row+dr[i];
			nxcol= col+dc[i];
			//cout<<nxrow<<" "<<nxcol<<endl;
			if(!inside(nxrow,nxcol))continue;
			if(grid[nxrow][nxcol]=='T')continue;
			//cout<<"test"<<endl;
			if(intest[nxrow][nxcol]!=INF)continue;
			
			intest[nxrow][nxcol] = intest[row][col]+1;
			q.push(mp(nxrow,nxcol));
		}
	}
	goal=intest[srow][scol];
	rep(i,1,R){
		rep(j,1,C){
			if(grid[i][j]-'0'>0 && grid[i][j]<58){
				srow=i,scol=j;
				if(intest[srow][scol]<=goal)ans+=(grid[i][j]-'0');
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}