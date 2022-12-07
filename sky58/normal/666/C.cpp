#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
typedef pair<pint,int> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
char s[114514];
int out[114514];
lint num[114514],sum[114514];
vector<tint> v;
vector<lint> zyo,rz,z2,z26;
lint mo=1000000007;
lint extgcd(lint a, lint b, lint &x, lint &y) {
  lint g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
lint invMod(lint a, lint m) {
  lint x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
lint co(int a,int b){
	if(a<b || a<0 || b<0) return 0;
	return ((zyo[a]*rz[a-b])%mo*rz[b])%mo;
}
int main()
{
	int n=0,m,t;
	zyo.pb(1);rz.pb(1);z2.pb(1);z26.pb(1);
	rep(i,110000){
		zyo.pb((zyo[i]*(i+1))%mo);
		rz.pb(invMod(zyo[i+1],mo));
		z26.pb((z26[i]*26)%mo);
		z2.pb((z2[i]*25)%mo*invMod(26,mo)%mo);
	}
	scanf("%d",&m);
	scanf("%s",&s);
	//cout<<strlen(s)<<endl;
	rep(i,m){
		scanf("%d",&t);
		if(t==2){
			scanf("%d",&t);
			v.pb(mp(mp(strlen(s),t),n));n++;
		}
		else{
			scanf("%s",&s);
			//cout<<strlen(s)<<endl;
		}
	}
	sort(All(v));
	rep(i,n){
		int x=v[i].fi.fi,y=v[i].fi.se;
		if(i==0 || x!=v[i-1].fi.fi){
			sum[0]=0;
			rep(j,100010){
				if(j<x-1) num[j]=0;
				else num[j]=co(j,x-1)*z2[j-x+1]%mo;
				sum[j+1]=sum[j]+num[j];if(sum[j+1]>mo) sum[j+1]-=mo;
			}
		}
		if(y<x) out[v[i].se]=0;
		else out[v[i].se]=(z26[y-x]*sum[y])%mo;
	}
	rep(i,n) printf("%d\n",(int)out[i]);
}