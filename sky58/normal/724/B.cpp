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
int ma[25][25],m2[25][25];
int n,m;
bool cal(void){
	rep(i,n){
		int t=0;
		rep(j,m){
			if(j+1!=m2[i][j]) t++;
		}
		if(t>2) return false;
	}
	return true;
}
string ok(void){
	rep(i,n) rep(j,m){
		m2[i][j]=ma[i][j];
	}
	if(cal()) return "YES";
	rep(i,m) REP(j,i+1,m){
		rep(k,n) rep(l,m) m2[k][l]=ma[k][l];
		rep(k,n) swap(m2[k][i],m2[k][j]);
		/*rep(k,n){
			rep(l,m) cout<<m2[k][l]<<' ';cout<<endl;
		}
		cout<<endl;*/
		if(cal()) return "YES";
	}
	return "NO";
}
int main()
{
	cin>>n>>m;
	rep(i,n) rep(j,m) cin>>ma[i][j];
	cout<<ok()<<endl;
}