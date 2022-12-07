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

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	int x,t,a,aa,b,bb;
	cin >> x >> t >> a >> b >> aa >> bb;
	for (int i=0;i<t;i++)for (int j=0;j<t;j++)if (a-aa*i+b-bb*j==x){
		puts("YES");
		return 0;
	}
	for (int j=0;j<t;j++)if (b-bb*j==x){
		puts("YES");
		return 0;
	}
	for (int j=0;j<t;j++)if (a-aa*j==x){
		puts("YES");
		return 0;
	}
	if (!x)puts("YES");else 
	puts("NO");
	return 0;
}