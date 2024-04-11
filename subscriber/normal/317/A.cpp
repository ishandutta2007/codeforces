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

long long x,y,xx,yy,m;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> x >> y >> m;
	if (x>=m || y>=m){
		puts("0");
		return 0;
	}
	if (x<=0 && y<=0){
		puts("-1");
		return 0;
	}
	if (x>y)swap(x,y);
	long long gg=0;
	if (x<0) {
		gg+=(-x)/y;
		x+=gg*y;
	}
	int ans = 1e9;
	for (int i=0;i<100;i++){
		for (int o=0;o<pw(15);o++){
			xx = x;
			yy = y;
			for (int j=0;j<15;j++){
				if (xx>=m || yy>=m)ans=min(ans,i+j);
				if (o&pw(j))xx+=yy;else yy+=xx;
			}
		}
		if (x>y)y+=x;else x+=y;
	}
	cout << ans+gg << endl;
	return 0;
}