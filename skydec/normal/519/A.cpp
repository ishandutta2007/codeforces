#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
char a[9][9];
int zhi[512];
int main(){
	int n=8;
	rep(i,1,n)scanf("%s",a[i]+1);
	zhi['Q']=9;
	zhi['R']=5;
	zhi['B']=zhi['N']=3;
	zhi['P']=1;
	
	zhi['q']=-9;
	zhi['r']=-5;
	zhi['b']=zhi['n']=-3;
	zhi['p']=-1;
	
	int ans=0;
	rep(i,1,n)rep(j,1,n)ans+=zhi[a[i][j]];
	if(ans<0)printf("Black");
	else if(ans>0)printf("White");
	else printf("Draw");
	return 0;
}