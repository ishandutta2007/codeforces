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
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
bool sumi[12][12][12];
string ma[12][12];
int dx[6]={1,-1,0,0,0,0},dy[6]={0,0,1,-1,0,0},dz[6]={0,0,0,0,1,-1};
int k,n,m,out=0;
void dfs(int x,int y,int z){
//	cout<<x<<' '<<y<<' '<<z<<endl;
	if(sumi[x][y][z]) return;
	if(ma[x][y][z]=='#') return;
	sumi[x][y][z]=true;out++;
	for(int i=0;i<6;i++){
		int nx=x+dx[i],ny=y+dy[i],nz=z+dz[i];
		if(nx<k && nx>=0 && ny<n && ny>=0 && nz<m && nz>=0) dfs(nx,ny,nz);
	}
	return;
}
int main()
{
	int i,j,x,y;string s;
	cin>>k>>n>>m;
	for(i=0;i<k;i++){
//		cin>>s;
		for(j=0;j<n;j++) cin>>ma[i][j];
	}
//	cin>>s;
//	for(i=0;i<k;i++) for(j=0;j<n;j++) cout<<ma[i][j]<<endl;
	cin>>x>>y;dfs(0,x-1,y-1);
	cout<<out<<endl;
	return 0;
}