#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>

using namespace std;

string s[22][22];
int k,n,m,x,y,ans=0;

void rec(int z,int x,int y){
	if (z<0||x<0||y<0||z>=k||x>=n||y>=m||s[z][x][y]=='#')return;
	s[z][x][y]='#';
	ans++;
	rec(z+1,x,y);
	rec(z-1,x,y);
	rec(z,x+1,y);
	rec(z,x-1,y);
	rec(z,x,y-1);
	rec(z,x,y+1);
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> k >> n >> m;
	for (int i=0;i<k;i++)for (int j=0;j<n;j++)cin >> s[i][j];
	cin >> x >> y;
	rec(0,x-1,y-1);
	cout << ans << endl;
	return 0;
}