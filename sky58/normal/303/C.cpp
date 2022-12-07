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
int n,step,amax=1000000,k;
bool sumi[5100];
int t[5][3];
vector <pint> dist[1000010];
vector <int> v,q;
stack<tint> st;

bool cal(int a,int b){
	rep(i,k){
		if(t[i][0]<0){t[i][0]=a;t[i][1]=b;return true;}
		if(t[i][1]<0){
			if(t[i][0]==a || t[i][1]==b) return true;
		}
		if(t[i][1]>=0){
			if(t[i][0]==a || t[i][0]==a){
				t[i][1]=-1;return true;
			}
			if(t[i][1]==a || t[i][1]==a){
				t[i][0]=t[i][1];t[i][1]=-1;return true;
			}
		}
	}
	return false;
}

int main()
{
	int a;
	cin>>n>>k;
	rep(i,n){
		cin>>a;v.pb(a);
	}
	sort(All(v));
	rep(i,n) REP(j,i+1,n){
		if(v[j]-v[i]>=n-k){
			if(dist[v[j]-v[i]].size()<=k+1) dist[v[j]-v[i]].pb(mp(i,j));
		}
	}
	memset(sumi,false,sizeof(sumi));
	REP(i,n-k,amax+2){
		rep(j,k) t[j][0]=t[j][1]=-1;int f=0;
		for(int now=i;f<1;now+=i){
			if(now>amax){cout<<i<<endl;return 0;}
			rep(pos,dist[now].size()){
				int a=dist[now][pos].fi,b=dist[now][pos].se;
				if(!cal(a,b)){f=1;break;}
			}
		}
	}
	return 0;
}