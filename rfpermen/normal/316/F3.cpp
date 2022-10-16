#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,N) for(int i = n; i<=N; i++)
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
const int MAX = 1600 + 5;
const int dr[] = {0,0,1,-1,1,-1,1,-1};
const int dc[] = {1,-1,0,0,1,1,-1,-1};

int n,m,nr,nc,cnt,ct;
bool grid[MAX][MAX], x[MAX][MAX], y[MAX][MAX], z[MAX][MAX], val;
vector<int> ans;
pii cur;
bool inside(int r,int c){return r>0 && r<=n && c>0 && c<=m;}
void dfs(int r,int c){
	grid[r][c] = 0;
	x[r][c] = 1;
	rep(i,0,3){
		nr = r+dr[i], nc = c+dc[i];
		if(!grid[nr][nc])continue;
		dfs(nr,nc);
	}
}
void cs(){
	rep(r,1,n)rep(c,1,m){
		if(!x[r][c])continue;
		if(!inside(r+1,c+1))continue;
		val = 1;
		rep(i,r,r+1)rep(j,c,c+1)if(!x[i][j])val = 0;
		if(val)rep(i,r,r+1)rep(j,c,c+1)y[i][j] = 1;
	}
}
void cas(){
	rep(r,1,n)rep(c,1,m){
		if(!x[r][c])continue;
		if(!inside(r-1,c-1))continue;
		if(!inside(r+2,c+2))continue;
		val = 1;
		rep(i,r-1,r+2)rep(j,c-1,c+2)if(!x[i][j]){
			val = 0; break;
		}
		if(val)rep(i,r-1,r+2)rep(j,c-1,c+2)z[i][j] = 1;
	}
	rep(r,1,n)rep(c,1,m)z[r][c]^=y[r][c];
}
void cast(){
	rep(r,1,n)rep(c,1,m){
		if(!z[r][c])continue;
		if(!inside(r+1,c+1))continue;
		val = 1;
		rep(i,r,r+1)rep(j,c,c+1)if(!z[i][j])val = 0;
		y[r][c] = val;
	}
}
void df(int r,int c){
	ct++;
	y[r][c] = 0;
	rep(i,0,7){
		nr = r+dr[i], nc = c+dc[i];
		if(!y[nr][nc])continue;
		df(nr,nc);
	}
}
void hit(){
	rep(i,1,n)rep(j,1,m){
		if(!y[i][j])continue;
		ct = 0;
		df(i,j);
		if(ct>3)cnt++;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)rep(j,1,m)cin>>grid[i][j];
	rep(i,1,n)rep(j,1,m){
		if(!grid[i][j])continue;
		memset(x,0,sizeof x);
		memset(y,0,sizeof y);
		memset(z,0,sizeof z);
		dfs(i,j);
		cs();
		cas();
		memset(y,0,sizeof y);
		cast();
		cnt = 0;
		hit();
		ans.pb(cnt);
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i<<" ";
	return 0;
}