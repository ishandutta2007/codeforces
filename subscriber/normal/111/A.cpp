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

long long x,y,n;
int ans[111111];


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> x >> y;
	long long s=n,o=n;
	for (int i=0;i<n;i++)ans[i]=1;
	while (s<x){
		s-=ans[0]*1ll*ans[0];
		ans[0]++;
		s+=ans[0]*1ll*ans[0];
		o++;
		if (o>y)break;
	}
	if (s>=x&&o<=y){
		for (int i=0;i<n;i++)printf("%d\n",ans[i]);
		return 0;
	}
	puts("-1");
	return 0;
}