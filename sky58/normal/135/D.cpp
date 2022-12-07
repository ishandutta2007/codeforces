#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
bool so[1100][1100];
int wa[1100][1100];
int dx[8]={0,0,1,-1,1,1,-1,-1},dy[8]={1,-1,0,0,-1,1,-1,1};
int h,w;
string ma[1100];
vector <pint> wav,cl;
struct unionf{
	vector <int> data;
	unionf(int size):data(size,-1){}
	bool unions(int x,int y){
		x=root(x);y=root(y);
		if(x!=y){
			if(data[y]<data[x]){int d=x;x=y;y=d;}
			data[x]+=data[y];data[y]=x;
		}
		return x!=y;
	}
	bool finds(int x,int y){
		return root(x)==root(y);
	}
	int root(int x){
		return data[x]<0?x:data[x]=root(data[x]);
	}
};
bool in(int x,int y){
	if(x<0 || y<0 || x>=h || y>=w) return false;return true;
}
void dfs1(int x,int y){
	if(so[x][y]) return;
	if(ma[x][y]=='1') return;
	so[x][y]=true;
	int i;
	rep(i,8){
		int nx=x+dx[i],ny=y+dy[i];
		if(in(nx,ny)) dfs1(nx,ny);
	}
	return;
}
void dfs2(int x,int y){
	if(so[x][y]) return;
	if(ma[x][y]=='1'){
		if(wa[x][y]<0){
			wa[x][y]=wav.size();wav.pb(mp(x,y));
		}
		return;
	}
	so[x][y]=true;
	int i;
	rep(i,8){
		int nx=x+dx[i],ny=y+dy[i];
		if(in(nx,ny)) dfs2(nx,ny);
	}
	return;
}
int main()
{
	int i,j,k,l,out=0;
	cin>>h>>w;
	rep(i,h) cin>>ma[i];
	memset(so,false,sizeof(so));//memset(wa,false,sizeof(wa));
	rep(i,1100) rep(j,1100) wa[i][j]=-1;
	rep(i,h){dfs1(i,0);dfs1(i,w-1);}
	rep(i,w){dfs1(0,i);dfs1(h-1,i);}
	rep(i,h) rep(j,w){
		if(so[i][j] || ma[i][j]=='1') continue;
		dfs2(i,j);
		int f=0,t=wav.size();
//		cout<<i<<' '<<j<<' '<<t<<endl;
		unionf uni(t);
		rep(k,t){
			int x=wav[k].fi,y=wav[k].se,s=0;
//			cout<<x<<' '<<y<<endl;
			rep(l,4){
				int nx=x+dx[l],ny=y+dy[l];
				if(in(nx,ny)){
					if(wa[nx][ny]>-1){s++;uni.unions(k,wa[nx][ny]);}
				}
			}
			if(s!=2) f=1;
		}
		REP(k,1,t){
			if(!uni.finds(0,k)) f=1;
		}
		if(f<1) out=max(out,k);
		rep(k,t){
			int x=wav[k].fi,y=wav[k].se;wa[x][y]=-1;
		}
		wav.clear();
	}
	rep(i,h-1) rep(j,w-1){
		if(ma[i][j]=='1' && ma[i+1][j]=='1' && ma[i][j+1]=='1' && ma[i+1][j+1]=='1') out=max(4,out);
	}
	cout<<out<<endl;
	return 0;
}