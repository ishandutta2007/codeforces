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

int n,o,aa,oo,a[5222][5222],k[5555],u[5555];
set<pt>S;
set<pt>::iterator it;
vector<pt>ans;
long long x,y,m;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int j=0;j<n;j++){
		cin >> k[j] >> a[j][0] >> x >> y >> m;
		for (int i=1;i<k[j];i++)a[j][i]=(a[j][i-1]*x+y)%m;
		oo+=k[j];
	}
	if (oo>200000){
		for(;;){
			for (int i=0;i<n;i++)u[i]++;
			for (int i=0;i<n;i++){
				while (u[i]<k[i]&&a[i][u[i]]>=a[i][u[i]-1])u[i]++;
			}
			int t=0;
			for (int i=0;i<n;i++)if (u[i]<k[i])t=1;
			if (!t)break;
			aa++;

		}
		CC(aa);
		return 0;
	}
	for (int i=0;i<n;i++)S.insert(mp(a[i][0],i));
	o=-1;
	for (int i=0;i<oo;i++){
		it=S.lower_bound(mp(o,0));
		if (it==S.end())aa++,it=S.begin();
		if (oo<=200000)ans.pb(*it);
		o=(*it).F;
		int g=(*it).S;
		S.erase(it);
		u[g]++;
		if (u[g]<k[g])S.insert(mp(a[g][u[g]],g));
	}
	CC(aa);
	if (oo<=200000){
		for (int i=0;i<oo;i++)printf("%d %d\n",ans[i].F,ans[i].S+1);
	}

	return 0;
}