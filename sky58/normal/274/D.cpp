#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
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
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector <int> kaikin[110000];
bool aru[110000];
int a[110000],out[110000],rimiter[110000],hai[110000],it[110000];
int main()
{
	int i,j,n,m,k;queue <int> q;
	memset(aru,false,sizeof(aru));
	memset(rimiter,0,sizeof(rimiter));
	memset(it,0,sizeof(it));
	cin>>n>>m;
	rep(i,n) rep(j,m) scanf("%d",&a[i*m+j]);
	rep(i,n){
		vector <pint> b;
		rep(j,m){
			if(a[i*m+j]<0) continue;aru[i*m+j]=true;
			rimiter[j]++;b.pb(mp(a[i*m+j],j));
		}
		sort(All(b));
		rep(j,b.size()){
			if(j>0 && b[j].fi==b[j-1].fi) hai[j]=hai[j-1];else hai[j]=j;
			kaikin[i*m+hai[j]].pb(b[j].se);
		}
	}
	rep(i,n) rep(j,kaikin[i*m].size()) rimiter[kaikin[i*m][j]]--;
	rep(i,m){if(rimiter[i]<=0) q.push(i);}
	rep(i,m){
		if(q.empty()){cout<<"-1"<<endl;return 0;}
		int t=q.front();q.pop();out[i]=t;
		rep(j,n){
			if(aru[j*m+t]){
				it[j]++;
				rep(k,kaikin[j*m+it[j]].size()){
					int u=kaikin[j*m+it[j]][k];
					rimiter[u]--;
					if(rimiter[u]<=0) q.push(u);
				}
			}
		}
	}
	rep(i,m){
		cout<<out[i]+1;
		if(i<m-1) cout<<' ';else cout<<endl;
	}
	return 0;
}