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
bool gr[110][110],know[110][110];
bool sumi[110];
int n;
void dfs(int a){
	int i;
	if(sumi[a]) return;
	sumi[a]=true;
	rep(i,n){
		if(!sumi[i] && gr[a][i]) dfs(i);
	}
	return;
}
int main()
{
	int i,j,k,m,a,f=0,out=0;
	memset(know,false,sizeof(know));
	memset(gr,false,sizeof(gr));
	memset(sumi,false,sizeof(sumi));
	cin>>n>>m;
	rep(i,n){
		cin>>k;
		if(k>0) f=1;
		rep(j,k){cin>>a;know[i][a-1]=true;}
	}
	if(f<1){cout<<n<<endl;return 0;}
	rep(i,n) rep(j,n) rep(k,m){
		if(know[i][k] && know[j][k]) gr[i][j]=gr[j][i]=true;
	}
	rep(i,n) rep(j,n){
		//if(gr[i][j]) cout<<i<<' '<<j<<endl;
	}
	rep(i,n){
		if(!sumi[i]){
			dfs(i);out++;
		}
	}
	cout<<out-1<<endl;return 0;
}