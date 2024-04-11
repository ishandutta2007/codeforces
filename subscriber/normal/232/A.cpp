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
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int k,n,ma=0,x,y,r,s;
char a[211][211];

int g(int x,int y){
	int r=0;
	for (int i=0;i<n;i++)if (a[x][i]=='1'&&a[y][i]=='1')r++;
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> k;
	n=100;
	for (int i=0;i<n;i++)for (int j=0;j<n;j++)a[i][j]='0';
	while (s!=k){
		x=rand()%n;
		y=rand()%n;
		if (x==y)continue;
		if (a[x][y]=='1'&&s>k)s-=g(x,y),a[x][y]='0',a[y][x]='0';else
		if (a[x][y]=='0'&&s<k)s+=g(x,y),a[x][y]='1',a[y][x]='1';
	}
	for (int i=0;i<n;i++)for (int j=0;j<i;j++)for (int k=0;k<j;k++)if (a[i][j]=='1'&&a[j][k]=='1'&&a[i][k]=='1')r++;
	CC(n);
	for (int i=0;i<n;i++)puts(a[i]);
	return 0;
}