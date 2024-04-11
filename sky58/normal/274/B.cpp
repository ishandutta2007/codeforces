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
lint mi[110000],ma[110000],c[110000];
vector <int> gr[110000];
void dfs(int now,int pre){
	int i;
	rep(i,gr[now].size()){
		int t=gr[now][i];if(t==pre) continue;
		dfs(t,now);mi[now]=max(mi[now],mi[t]);ma[now]=max(ma[now],ma[t]);
	}
	c[now]-=mi[now];c[now]+=ma[now];
	if(c[now]<0) ma[now]-=c[now];else mi[now]+=c[now];
	return;
}
int main()
{
	int i,n,a,b;
	memset(mi,0,sizeof(mi));memset(ma,0,sizeof(ma));
	cin>>n;
	rep(i,n-1){
		scanf("%d %d",&a,&b);a--;b--;
		gr[a].pb(b);gr[b].pb(a);
	}
	rep(i,n){scanf("%d",&a);c[i]=a;}
	dfs(0,-1);
	lint out=mi[0]+ma[0];
	//cout<<mi[0]<<' '<<ma[0]<<' '<<c[0]-mi[0]+ma[0]<<endl;
	//if(c[0]-mi[0]+ma[0]>0LL) out+=c[0]-mi[0]+ma[0];
	//else out-=c[0]-mi[0]+ma[0];
	cout<<out<<endl;
	return 0;
}