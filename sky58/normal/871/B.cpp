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
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
ostream &operator<<(ostream &os, const vector<int> &a) {
	os<<"[";
	rep(i,a.size()){
		os<<a[i];
		if(i<a.size()-1) os<<",";
	}
	os<<"]";
	return os; 
}
bool debugMode=false;
int b0p[5140],p0b[5140];
int debugp[5140],debugb[5140];
int n;
vector<vector<int> > cp;
int getnum(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int ret;
	if(debugMode){
		return (debugp[x]|debugb[y]);
	}
	scanf("%d",&ret);
	return ret;
}
void cal(int b0){
	vector<int> p,b(n,0);
	rep(i,n){
		p.pb((b0^b0p[i]));
		if(p[i]<0 || p[i]>=n) return;
	}
	//cout<<b0<<endl;
	rep(i,n) b[p[i]]=i;
	/*if(b0==3){
		rep(i,n) cout<<b0p[i]<<' '<<p0b[i]<<endl;
		cout<<p<<' '<<b<<endl;
	}*/
	rep(i,n){
		if((p[0]^b[i])!=p0b[i]) return;
	}
	//cout<<'a'<<b0<<endl;
	cp.pb(p);
}
int main()
{
	cin>>n;
	if(debugMode){
		rep(i,n) cin>>debugp[i];
		rep(i,n) debugb[debugp[i]]=i;
	}
	rep(i,n) b0p[i]=getnum(i,0);
	rep(i,n) p0b[i]=getnum(0,i);
	//rep(i,n) cout<<b0p[i]<<' '<<p0b[i]<<endl;
	rep(i,n) cal(i);
	printf("!\n");
	printf("%d\n",cp.size());
	rep(i,n){
		printf("%d",cp[0][i]);
		if(i<n-1) printf(" ");else printf("\n");
	}
}