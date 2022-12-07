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
#define pw(x) (1ll<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int a,b;
int solve(int x){
	int l1 = 0, l2 = 0;
	while (a % x == 0) l1++, a /= x;
	while (b % x == 0) l2++, b /= x;
	return abs(l1-l2);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> a >> b;
	int ans = 0;
	ans += solve(2);
	ans += solve(3);
	ans += solve(5);
	if (a != b) puts("-1"); else cout << ans << endl;
	return 0;
}