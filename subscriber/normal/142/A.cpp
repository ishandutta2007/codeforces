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

long long n,x,y,ans1=1e18,ans2=0;
vector<long long>e;


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=1;i*i<=n;i++)if (n%i==0)e.pb(i),e.pb(n/i);
	for (int i=0;i<e.size();i++)for (int j=0;j<i;j++){
		x=e[i]*e[j];
		if (n%x)continue;
		y=n/x;
		ans1=min(ans1,(e[i]+1)*(e[j]+2)*(y+2)-n);
		ans1=min(ans1,(e[i]+2)*(e[j]+1)*(y+2)-n);
		ans1=min(ans1,(e[i]+2)*(e[j]+2)*(y+1)-n);
		ans2=max(ans2,(e[i]+1)*(e[j]+2)*(y+2)-n);
		ans2=max(ans2,(e[i]+2)*(e[j]+1)*(y+2)-n);
		ans2=max(ans2,(e[i]+2)*(e[j]+2)*(y+1)-n);
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}