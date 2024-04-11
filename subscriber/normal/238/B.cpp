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

int n,h,ans[111111],ma,mi;
pair<int,int>q[111111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> h;
	for (int i=0;i<n;i++)scanf("%d",&q[i].F),q[i].S=i;
	sort(q,q+n);
	ans[q[0].S]=1;
	for (int i=1;i<n;i++)ans[q[i].S]=2;
	ma=q[0].F+q[n-1].F+h;
	if (n>2)ma=max(ma,q[n-1].F+q[n-2].F);
	mi=q[0].F+q[1].F+h;
	if (n>2)mi=min(mi,q[1].F+q[2].F);
	if (n>2&&ma-mi>q[n-1].F+q[n-2].F-q[0].F-q[1].F){
		CC(q[n-1].F+q[n-2].F-q[0].F-q[1].F);
		for (int i=0;i<n;i++)printf("%d ",1);
		return 0;
	}
	CC(ma-mi);
	for (int i=0;i<n;i++)printf("%d ",ans[i]);
	return 0;
}