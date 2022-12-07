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
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector <vector <int> > gr,rgr;
bool sumi1[110000],sumi2[110000];
int st[110000];
vector <int> now1,next1,now2,next2,cl;
void ed1(int a){
	if(!sumi1[a] && st[a]!=1){sumi1[a]=true;next1.pb(a);}return;
}
void ed2(int a){
	if(!sumi2[a]){sumi2[a]=true;if(st[a]!=1) next2.pb(a);}return;
}
int main()
{
	int i,j,n,m,a,b;
	cin>>n>>m;
	memset(sumi1,false,sizeof(sumi1));
	memset(sumi2,false,sizeof(sumi2));
	rep(i,n){
		scanf("%d",&st[i]);//if(st[i]==1) ed1(i);if(st[i]==2) ed2(i);
	}
	rep(i,n+10){gr.pb(cl);rgr.pb(cl);}
	rep(i,m){
		scanf("%d %d",&a,&b);gr[a-1].pb(b-1);rgr[b-1].pb(a-1);
	}
//	cout<<n<<' '<<m<<endl;
//	now1=next1;next1=cl;now2=next2;next2=cl;
	rep(i,n){
		if(st[i]==1){now1.pb(i);sumi1[i]=true;}
		if(st[i]==2){now2.pb(i);sumi2[i]=true;}
	}
	while(now1.size()>0){
		rep(i,now1.size()){
			int now=now1[i];
			rep(j,gr[now].size()) ed1(gr[now][j]);
		}
		now1=next1;next1=cl;
	}
	while(now2.size()>0){
		rep(i,now2.size()){
			int now=now2[i];
			rep(j,rgr[now].size()) ed2(rgr[now][j]);
		}
		now2=next2;next2=cl;
	}
	rep(i,n){
		if(sumi1[i] && sumi2[i]) printf("1\n");else printf("0\n");
	}
	return 0;
}