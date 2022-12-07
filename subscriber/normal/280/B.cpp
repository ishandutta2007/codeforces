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

int n,a[222222],ans=0,st,e[222222],l,r,c;

void rr(){
	st=0;
	for (int i=0;i<n;i++){
		while (st>0&&a[i]>e[st-1])st--;
		if (st>0)ans=max(ans,a[i]^e[st-1]);
		e[st++]=a[i];
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	rr();
	reverse(a,a+n);
	rr();
	cout << ans << endl;
	return 0;

}