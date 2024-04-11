/*----------------by syr----------------*/
/*
  -----  -----  -----
  |   |  |---|    _/
  |   |  | \_    /
  -----  |   \  -----

  |---\  \   /  |\  /|
  |   |   \_/   | \/ |
  |   |   / \   |    |
  |---/  /   \  |    |
*/
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<limits>
#include<list>
#include<map>
#include<math.h>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<sstream>
#include<string>
#include<time.h>
#include<utility>
#include<vector>

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define REP(i,x,y) for(int i=(x);i<=(y);++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;

const int INF=1e9+7;

int n;
int dis[10][10];
bool vis[10][10];
pii nxt[10][10];

void go(int x,int y){
	int cx=0,cy=0;
	while(cx!=x||cy!=y){
		printf("%c%c ",cx+'a',cy+'1');
		int nx,ny;
		nx=nxt[cx][cy].fst,ny=nxt[cx][cy].snd;
		cx=nx,cy=ny;
	}
	printf("%c%c ",x+'a',y+'1');
	if(y==7){
		printf("%c%c h8\n",x+'a'+1,y+'1');
	}else{
		printf("h%c h8\n",y+'1');
	}
	return;
}

void dfs(int x,int y,int dep,string ans){
	vis[x][y]=1;
	ans+=(char)x+'a';
	ans+=(char)y+'1';
	ans+=' ';
	if(x==7&&y==7&&dep==n){
		cout<<ans<<endl;
		exit(0);
	}
	FOR(i,0,8){
		if(vis[x][i]==0) dfs(x,i,dep+1,ans);
	}
	FOR(i,0,8){
		if(vis[i][y]==0) dfs(i,y,dep+1,ans);
	}
	vis[x][y]=0;
	return;
}

int main(){
	scanf("%d",&n);
	FOR(i,0,8){
		if(i&1){
			dis[i][7]=dis[i-1][7]+1,nxt[i-1][7]=MP(i,7);
			for(int j=6;j>=0;--j) dis[i][j]=dis[i][j+1]+1,nxt[i][j+1]=MP(i,j);
		}else{
			if(!i) dis[i][0]=0;
			else dis[i][0]=dis[i-1][0]+1,nxt[i-1][0]=MP(i,0);
			FOR(j,1,8) dis[i][j]=dis[i][j-1]+1,nxt[i][j-1]=MP(i,j);
		}
	}
	if(n<=56){
		FOR(i,0,8){
			FOR(j,0,8){
				if(dis[i][j]+2==n){
					go(i,j);
					return 0;
				}
			}
		}
	}else{
		dfs(0,0,0,"");
	}
	return 0;
}