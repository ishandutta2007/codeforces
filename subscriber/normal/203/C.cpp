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

int d,a,b,x,y,ans,n;
pair<int,int>q[222222];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >>n >> d >> a >> b;
	for (int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		q[i]=mp(x*a+y*b,i);
	}
	sort(q,q+n);
	for (int i=0;i<n;i++)if (q[i].F>d)break;else{
		ans++;
		d-=q[i].F;
	}
	CC(ans);
	for (int i=0;i<ans-1;i++)printf("%d ",q[i].S+1);
	if (ans)CC(q[ans-1].S+1);
	return 0;
}