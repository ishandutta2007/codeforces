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
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
struct unionf{
	vector <int> data;
	unionf(int size):data(size,-1){}
	bool unions(int x,int y){
		x=root(x);y=root(y);
		if(x!=y){
			if(data[y]<data[x]){int d=x;x=y;y=d;}
			data[x]+=data[y];data[y]=x;
		}
		return x!=y;
	}
	bool finds(int x,int y){
		return root(x)==root(y);
	}
	int root(int x){
		return data[x]<0?x:data[x]=root(data[x]);
	}
	int find(int x){
		return -data[x];
	}
};
int ma[1141919],dp[1141919];
vector<int> gr[1141919];
int cal(int a){
	if(dp[a]>=0) return dp[a];
	int ret=0;
	rep(i,gr[a].size()) ret=max(ret,cal(gr[a][i]));
	return dp[a]=ret+1;
}
int main()
{
	int n,m;
	unionf uni(n*m+1141919);
	scanf("%d %d",&n,&m);
	rep(i,n) rep(j,m) scanf("%d",&ma[i*m+j]);
	rep(i,n){
		vector<pint> v;
		rep(j,m) v.pb(mp(ma[i*m+j],i*m+j));
		sort(All(v));
		rep(j,m-1){
			if(v[j].fi==v[j+1].fi){
				//cout<<v[j].se<<' '<<v[j+1].se<<endl;
				uni.unions(v[j].se,v[j+1].se);
			}
		}
	}
	rep(i,m){
		vector<pint> v;
		rep(j,n) v.pb(mp(ma[j*m+i],j*m+i));
		sort(All(v));
		rep(j,n-1){
			if(v[j].fi==v[j+1].fi){
				//cout<<v[j].se<<' '<<v[j+1].se<<endl;
				uni.unions(v[j].se,v[j+1].se);
			}
		}
	}
	/*rep(i,n){
		rep(j,m) cout<<uni.root(i*m+j)<<' ';cout<<endl;
	}*/
	
	rep(i,n){
		vector<pint> v;
		rep(j,m) v.pb(mp(ma[i*m+j],i*m+j));
		sort(All(v));
		rep(j,m-1){
			if(v[j].fi!=v[j+1].fi){
				int x=uni.root(v[j].se),y=uni.root(v[j+1].se);
				gr[y].pb(x);
			}
		}
	}
	rep(i,m){
		vector<pint> v;
		rep(j,n) v.pb(mp(ma[j*m+i],j*m+i));
		sort(All(v));
		rep(j,n-1){
			if(v[j].fi!=v[j+1].fi){
				int x=uni.root(v[j].se),y=uni.root(v[j+1].se);
				gr[y].pb(x);
			}
		}
	}
	
	memset(dp,-1,sizeof(dp));
	rep(i,n) rep(j,m){
		printf("%d",cal(uni.root(i*m+j)));
		if(j<m-1) printf(" ");else printf("\n");
	}
}