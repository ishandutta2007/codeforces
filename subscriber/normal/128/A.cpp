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
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;

char a[11][11];
int f[11][11][555];

void rec(int x,int y,int l){
	if (x<0||x>7||y<0||y>7||l>444||x-l+1>=0&&a[x-l+1][y]=='S'||x-l>=0&&a[x-l][y]=='S'||f[x][y][l])return;
	if (x==0&&y==7){
		puts("WIN");
		exit(0);
	}
	f[x][y][l]=1;
	for (int i=-1;i<2;i++)for (int j=-1;j<2;j++)rec(x+i,y+j,l+1);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	for (int i=0;i<8;i++)gets(a[i]);
	rec(7,0,0);
	puts("LOSE");
	return 0;
}