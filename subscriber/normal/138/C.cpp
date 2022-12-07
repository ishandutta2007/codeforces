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

int n,m,a,k,l,r,h,x,p=0,g[111];
pair<pair<int,int>,int>q[844444];
long double s,ans,ss;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> a >> h >> l >> r;
		q[k++]=mp(mp(a-h,0),100-l);
		q[k++]=mp(mp(a-1,2),100-l);
		q[k++]=mp(mp(a+1,0),100-r);
		q[k++]=mp(mp(a+h,2),100-r);
	}
	for (int i=0;i<m;i++){
		cin >> x >> a;
		q[k++]=mp(mp(x,1),a);
	}
	sort(q,q+k);
	for (int i=0;i<k;i++){
		if (q[i].F.S==1){
			s=q[i].S;
			for (int j=0;j<100;j++)for (int l=0;l<g[j];l++){
				if (s<1e-15)break;
				s*=j/100.;
			}
			ans+=s;
		}else if (q[i].F.S==0)g[q[i].S]++;else g[q[i].S]--;
	}
	cout << fixed << ans << endl;
	return 0;
}