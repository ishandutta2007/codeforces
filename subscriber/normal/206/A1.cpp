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

int n,k1,k2,f[2222][2222][2],p[2222][2222][2],a[222222],b[222222],o,aa;
vector<pt>ans;
long long x,y,m;

void gox(){
	if (k1+k2<=200000)ans.pb(mp(a[x],1));
	o=a[x];
	x++;
}
void goy(){
	if (k1+k2<=200000)ans.pb(mp(b[y],2));
	o=b[y];
	y++;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	m1(f);
	if (n==2){
		cin >> k1 >> a[0] >> x >> y >> m;
		for (int i=1;i<k1;i++)a[i]=(a[i-1]*x+y)%m;
		cin >> k2 >> b[0] >> x >> y >> m;
		for (int i=1;i<k2;i++)b[i]=(b[i-1]*x+y)%m;
		o=-1;
		x=y=0;
		while (x<k1||y<k2){
			int f1=(x<k1&&a[x]>=o);
			int f2=(y<k2&&b[y]>=o);
			if (f1&&f2){
				if (a[x]<b[y])gox();else goy();
			}else if (f1)gox();else if (f2)goy();
			if (f1+f2==0){
				aa++;
				f1=x<k1;
				f2=y<k2;
				if (f1&&f2){
					if (a[x]<b[y])gox();else goy();
				}else if (f1)gox();else if (f2)goy();
			}
		}
	}
	CC(aa);
	if (k1+k2<=200000){
		for (int i=0;i<k1+k2;i++)printf("%d %d\n",ans[i].F,ans[i].S);
	}
	return 0;
}