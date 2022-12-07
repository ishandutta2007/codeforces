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

int n,ans[444444];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	int t=n/2*2;
	if (t%4==2){
		puts("-1");
		return 0;
	}
	if (n%2)ans[n/2]=n/2;
	int x=0;
	while (x<n/2){
		ans[x]=x+1;
		ans[x+1]=n-1-x;
		ans[n-1-x]=n-2-x;
		ans[n-2-x]=x;
		x+=2;
	}
	for (int i=0;i<n-1;i++)printf("%d ",ans[i]+1);
	cout << ans[n-1]+1 << endl;
	return 0;
}