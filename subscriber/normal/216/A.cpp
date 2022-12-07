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

int a,b,c,ans;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> a >> b >> c;
	ans+=(b+c-1)*(a-1);
	a=1;
	ans+=(a+b-1)*(c-1);
	c=1;
	ans+=(a+c-1)*(b-1);
	ans++;
	CC(ans);
	return 0;
}