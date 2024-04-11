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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector <pint> ba;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
string ma[55];
int nex[55][55][5],ney[55][55][5];
int main()
{
	int x=0,y=0,d=1,c=0,i,j,k,l,n,h,w,m;
	cin>>h>>n;rep(i,h) cin>>ma[i];w=ma[0].size();
	rep(i,h) rep(j,w) rep(k,4){
		l=i;m=j;
		while(l>=0 && l<h && m>=0 && m<w){
			if(ma[l][m]==ma[i][j]){nex[i][j][k]=l;ney[i][j][k]=m;}else break;
			l+=dx[k];m+=dy[k];
		}
	}
	for(i=1;i<=n;i++){
		int lx=nex[x][y][d],ly=ney[x][y][d],mx=nex[lx][ly][c],my=ney[lx][ly][c],nx=mx+dx[d],ny=my+dy[d];
		if(nx<0 || ny<0 || nx>=h || ny>=w){
			if((d+4-c)%4==1) c=(c+2)%4;
			else{int e=c;c=d;d=e;}
		}
		else{
			if(ma[nx][ny]=='0'){
				if((d+4-c)%4==1) c=(c+2)%4;
				else{int e=c;c=d;d=e;}
			}
			else{
				x=nx;y=ny;
			}
		}
	}
	cout<<ma[x][y]<<endl;
	return 0;
}