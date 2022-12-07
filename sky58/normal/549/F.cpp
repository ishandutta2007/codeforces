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
typedef pair<int,map<int,lint> > pmap;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define N 364364
#define M 1141919
int K;
int a[N],cl[M],cr[M],memo[N];
lint out=0;
void cal(int l,int r){
	if(r<=l+1) return;
	//cout<<l<<' '<<r<<endl;
	int ml=0,mr=0,sl=0,sr=0,m=(l+r)/2,s=m-1,t=m;
	while(l<=s || t<r){
		if(s<l || (t<r && max(a[s],ml)>=max(a[t],mr))){
			mr=max(mr,a[t]);
			sr=(sr+a[t])%K;
			memo[t]=sr;cr[sr]++;
			out+=cl[(mr+K-sr)%K];
			t++;
		}
		else{
			ml=max(ml,a[s]);
			sl=(sl+a[s])%K;
			memo[s]=sl;cl[sl]++;
			out+=cr[(ml+K-sl)%K];
			s--;
		}
		//cout<<s<<' '<<t<<' '<<out<<endl;
	}
	REP(i,l,m) cl[memo[i]]--;
	REP(i,m,r) cr[memo[i]]--;
	cal(l,m);
	cal(m,r);
}
int main()
{
	int n;
	scanf("%d %d",&n,&K);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	memset(cl,0,sizeof(cl));
	memset(cr,0,sizeof(cr));
	cal(0,n);
	cout<<out<<endl;
}