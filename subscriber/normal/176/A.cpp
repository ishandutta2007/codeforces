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

int n,m,k,aa,s,a[111][111],b[111][111],c[111][111],ans;
vector<pt>v;
string o;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >>k;
	for (int i=0;i<n;i++){
		cin >> o;
		for (int j=0;j<m;j++)cin >> a[i][j] >> b[i][j] >> c[i][j];
	}
	for (int x=0;x<n;x++)for (int y=0;y<n;y++){
		v.clear();
		for (int i=0;i<m;i++)v.pb(mp(-(b[y][i]-a[x][i]),c[x][i]));
		sort(AL(v));
		s=k;
		aa=0;
		for (int i=0;i<m;i++)if (v[i].F>=0)break;else{
			int l=min(s,v[i].S);
			aa-=v[i].F*l;
			s-=l;
		}
		ans=max(ans,aa);
	}
	CC(ans);
	return 0;
}