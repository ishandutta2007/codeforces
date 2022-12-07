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
int now[114][114];
int ma[114][114];
int main()
{
	memset(now,0,sizeof(now));
	int h,w,out=0;string s;
	cin>>h>>w;
	rep(i,h){
		cin>>s;
		rep(j,w){
			if(s[j]=='B') ma[i][j]=-1;
			else ma[i][j]=1;
		}
	}
	for(int i=h;i>0;i--) for(int j=w;j>0;j--){
		//cout<<i<<' '<<j<<' '<<ma[i-1][j-1]<<' '<<now[i-1][j-1]<<endl;
		int t=ma[i-1][j-1]-now[i-1][j-1];
		if(t!=0){
			out++;
			rep(k,i) rep(l,j) now[k][l]+=t;
		}
	}
	cout<<out<<endl;
}