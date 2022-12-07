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

int n,m,a,b,ans;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> a >> b;
	a--;
	b--;
	if (a/m==b/m){
		puts("1");
		return 0;
	}
	ans=3;
	if (a/m+1==b/m)ans=2;
	if (b%m+1==a%m||b%m==m-1||a%m==0||b+1==n)ans=2;
	if (a%m==0&&b%m==m-1)ans=1;
	if (a%m==0&&b+1==n)ans=1;
	CC(ans);
	return 0;
}