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
string ma[1100];
int dx[9]={-1,-1,-1,-1,0,0,0,0,1},dy[9]={-1,0,1,2,-2,-1,2,3,-1};
bool sumi[12];
int main()
{
	int i,j,k,h,w;cin>>h>>w;
	for(i=0;i<h;i++) cin>>ma[i];
	for(i=0;i<h;i++) for(j=0;j<w;j++){
		if(ma[i][j]!='.') continue;
		int f=0;
		if(i<h-1) if(ma[i+1][j]=='.') f=1;
		if(j<w-1) if(ma[i][j+1]=='.' && f<1) f=2;
		if(f<1) continue;
		memset(sumi,false,sizeof(sumi));
		for(k=0;k<9;k++){
			int x=i+dx[k],y=j+dy[k];
			if(x<0 || x>=h || y<0 || y>=w) continue;
			if(ma[x][y]<='9' && ma[x][y]>='0') sumi[(ma[x][y]-'0')]=true;
		}
		for(k=0;sumi[k];k++){}
		ma[i][j]=(k+'0');if(f%2>0) ma[i+1][j]=(k+'0');if(f>1) ma[i][j+1]=(k+'0');
	}
	for(i=0;i<h;i++) for(j=0;j<w;j++){
		if(ma[i][j]!='.') continue;
		if(i>0) if(ma[i-1][j]>='0' && ma[i-1][j]<='9'){ma[i][j]=ma[i-1][j];continue;}
		if(j>0) if(ma[i][j-1]>='0' && ma[i][j-1]<='9'){ma[i][j]=ma[i][j-1];continue;}
		if(i<h-1) if(ma[i+1][j]>='0' && ma[i+1][j]<='9'){ma[i][j]=ma[i+1][j];continue;}
		if(j<w-1) if(ma[i][j+1]>='0' && ma[i][j+1]<='9'){ma[i][j]=ma[i][j+1];continue;}
		cout<<"-1"<<endl;return 0;
	}
	for(i=0;i<h;i++) cout<<ma[i]<<endl;
	return 0;
}