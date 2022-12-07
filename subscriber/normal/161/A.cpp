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

int n,m,x,y,z;
vector<pt>ans;
set<pt>s;
set<pt>::iterator ii;
pt q[111111];


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> x >> y;
	for (int i=0;i<n;i++)cin >> q[i].F;
	for (int i=0;i<n;i++)q[i].S=i;
	sort(q,q+n);
	for (int i=0;i<m;i++){
		cin >> z;
		s.insert(mp(z,i));
	}
	for (int i=0;i<n;i++){
		ii=s.lower_bound(mp(q[i].F-x,0));
		if (ii==s.end()||(*ii).F>q[i].F+y)continue;
		ans.pb(mp(q[i].S,(*ii).S));
		s.erase(ii);
	}
	CC(ans.size());
	for (int i=0;i<ans.size();i++)cout << ans[i].F+1 << " " << ans[i].S+1 << endl;
	return 0;
}