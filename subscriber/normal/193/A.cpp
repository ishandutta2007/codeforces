#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,m,t,w[111][111];
string a[111];

void rec(int x,int y){
	if (x<0||x>=n||y<0||y>=m||a[x][y]=='.'||w[x][y])return;
	w[x][y]=1;
	rec(x-1,y);
	rec(x+1,y);
	rec(x,y-1);
	rec(x,y+1);
}

bool oo(){
	int u=0;
	m0(w);
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)if (a[i][j]=='#'&&!w[i][j]){
		u++;
		rec(i,j);
	}
	return u>1;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)if (a[i][j]=='#')t++;
	if (t<3){
		puts("-1");
		return 0;
	}
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)if (a[i][j]=='#'){
		a[i][j]='.';
		if (oo()){
			puts("1");
			return 0;
		}
		a[i][j]='#';
	}
	puts("2");
	return 0;
}