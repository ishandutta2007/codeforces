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
typedef complex<double> pt;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
bool sumi[3][110000];
int n;
vector <pint> now,next,cl;
string s[3];
void aedge(int i,int a,int b){
	if(b<i || b>n) return;if(sumi[a][b]) return;
	if(s[a][b]=='X') return;
	sumi[a][b]=true;
	next.pb(mp(a,b));return;
}
int main()
{
	memset(sumi,false,sizeof(sumi));
	int i,j,k;
	cin>>n>>k;
	cin>>s[0];cin>>s[1];aedge(0,0,0);now=next;next=cl;
	rep(i,n+10){
		rep(j,now.size()){
			int x=now[j].fi,y=now[j].se;
			//cout<<i<<' '<<x<<' '<<y<<endl;
			if(y+k>n){cout<<"YES"<<endl;return 0;}
			aedge(i+1,x,y-1);aedge(i+1,x,y+1);aedge(i+1,1-x,y+k);
		}
		now=next;next=cl;
	}
	cout<<"NO"<<endl;return 0;
}