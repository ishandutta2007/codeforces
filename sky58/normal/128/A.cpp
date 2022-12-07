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
typedef long long lint;
#define mp make_pair
#define fi first.first
#define se first.second
#define th second
typedef pair<int,int> pint;
typedef pair<pint,int> tint;
#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
string ma[10];
bool sumi[10][10][10];
vector <tint> now,next,cl;
int dx[9]={-1,-1,-1,0,0,0,1,1,1},dy[9]={-1,0,1,-1,0,1,-1,0,1};
bool in(int a,int b){
	if(a<0 || a>7 || b<0 || b>7) return false;return true;
}
void aedge(int a,int b,int c){
	if(!sumi[a][b][c]){
		sumi[a][b][c]=true;next.pb(mp(mp(a,b),c));
	}
	return;
}
int main()
{
	int i,j;
	memset(sumi,false,sizeof(sumi));
	now.pb(mp(mp(7,0),0));sumi[7][0][0]=true;
	rep(i,8) cin>>ma[i];
	while(now.size()){
		rep(i,now.size()){
			int x=now[i].fi,y=now[i].se,t=now[i].th;
//			cout<<x<<' '<<y<<' '<<t<<endl;
			if(x==0 && y==7){
				cout<<"WIN"<<endl;return 0;
			}
			rep(j,9){
				int nx=x+dx[j],ny=y+dy[j],nt=min(8,t+1);
				if(!in(nx,ny)) continue;
				if(nx-t>=0){
					if(ma[nx-t][ny]=='S') continue;
					if(nx-nt>=0){
						if(ma[nx-nt][ny]=='S') continue;
					}
				}
//				cout<<nx<<' '<<ny<<' '<<nt<<endl;
				aedge(nx,ny,nt);
			}
		}
		now=next;next=cl;
	}
	cout<<"LOSE"<<endl;
	return 0;
}