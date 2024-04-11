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
int R,C,scol,fcol,srow,frow,row,col,nxrow,nxcol,T,mini;
int shortest[1005][1005];
vector<int> vrow[1005], vcol[1005];
char grid[1005][1005];
const int dr[4] = {-1,0,1,0};
const int dc[4] = {0,-1,0,1};
bool vis[1005][2];
const int INF=1e9;
queue<pair<pair<int,bool>,int> > q;
bool inside(int r,int c){
	return r>0 && c>0 && r<=R && c<=C;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>R>>C;
	rep(r,1,R){
		rep(c,1,C)cin>>grid[r][c];
	}
	rep(r,1,R){
		rep(c,1,C)if(grid[r][c]=='#')vrow[r].pb(c);
	}
	rep(c,1,C){
		rep(r,1,R)if(grid[r][c]=='#')vcol[c].pb(r);
	}
//	cout<<vrow[3].size()<<endl;
	q.push(mp(mp(R,true),0));
	while(!q.empty()){
		pair<pair<int,bool>,int > cur=q.front();
		q.pop();
		//cout<<q.size()<<endl;
		//if(vis[cur.fi.fi][cur.fi.se]==1)continue;
		if(cur.fi.se==0){
			int siz=vcol[cur.fi.fi].size();
			if(siz==0)continue;
			rep(i,0,siz-1){
				if(vcol[cur.fi.fi][i]==1){
					cout<<cur.se+1<<endl;
					return 0;
				}//cout<<"iiii"<<i<<endl;
			if(vis[vcol[cur.fi.fi][i]][0]==1)continue;
			vis[vcol[cur.fi.fi][i]][0]=1;
		//	cout<<"col "<<vcol[cur.first.fi][i]<<endl;
			q.push(mp(mp(vcol[cur.fi.fi][i],1),cur.se+1));
		}
		}else {
			int siz=vrow[cur.fi.fi].size();
			if(siz==0)continue;
			rep(i,0,siz-1){
				if(vis[vrow[cur.fi.fi][i]][1]==1)continue;
			//	cout<<cur.fi.fi<<endl;
			//	if(cur.first.fi==3)cout<<"hehe"<<endl;
				vis[vrow[cur.fi.fi][i]][1]=1;
			//	cout<<"row "<<vrow[cur.first.fi][i]<<endl;
				q.push(mp(mp(vrow[cur.fi.fi][i],0),cur.se+1));
				
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}