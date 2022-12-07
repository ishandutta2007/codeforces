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

int n,x,y;
double ans=0;
vector<int>v[222222];

void rec(int x,int p,int d){
	ans+=1./d;
	for (int i=0;i<v[x].size();i++)if (v[x][i]!=p)rec(v[x][i],x,d+1);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	rec(0,-1,1);
	printf("%.10lf\n",ans);
	return 0;
}