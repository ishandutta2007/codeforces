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
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int a,b;
double w[1111][1111],x,xx;

double rec(int a,int b,int o){
	if (a<0||b<0)return 0;
	if (w[a][b]!=-1)return w[a][b];
	double x=a/1./(a+b),xx;
	if (o==0){
		if (a==0)return 0;
		return w[a][b]=x+(1-x)*(1-rec(a,b-1,1));
	}else{
		if (a==0)return 1;
		if (a+b==1)return w[a][b]=x;
		xx=a/1./(a+b-1);
		return w[a][b]=x+(1-x)*(xx*(1-rec(a-1,b-1,0))+(1-xx)*(1-rec(a,b-2,0)));
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cout.precision(11);
	cin >> a >> b;
	for (int i=0;i<=a;i++)for (int j=0;j<=b;j++)w[i][j]=-1;
	CC(rec(a,b,0));
	return 0;
}