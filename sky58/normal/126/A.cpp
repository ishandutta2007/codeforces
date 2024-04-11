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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
bool ch(lint a,lint b,lint c,lint d){return a*d<=b*c;}
lint labs(lint a){if(a<0) return -a;return a;}
int main()
{
	lint t1,t2,t0,x1,x2,i,y,y1=0,y2=0,a,b,d1=10000000,d2=1,e1,e2;
	cin>>t1>>t2>>x1>>x2>>t0;
	a=t0-t1;b=t2-t0;
	if(t2==t0){
		if(t0==t1){
			cout<<x1<<' '<<x2<<endl;return 0;
		}
		else{
			cout<<"0 "<<x2<<endl;return 0;
		}
	}
	if(t0==t1){cout<<x1<<" 0"<<endl;return 0;}
	REP(i,1,x1+1){
		y=i*a/b;y=min(y,x2-1);
		e1=b*y-i*a;e2=i+y;
		if(e1>=0 && i+y>0 && ch(e1,e2,d1,d2)){y1=i;y2=y;d1=e1;d2=e2;}
		y++;e1=b*y-i*a;e2=i+y;
		if(e1>=0 && ch(e1,e2,d1,d2)){y1=i;y2=y;d1=e1;d2=e2;}
	}
	REP(i,1,x2+1){
		y=i*b/a;y=min(y,x1-1);
		e1=b*i-y*a;e2=i+y;
		if(e1>=0 && i+y>0 && ch(e1,e2,d1,d2)){y1=y;y2=i;d1=e1;d2=e2;}
		y++;e1=b*i-y*a;e2=i+y;
		if(e1>=0 && ch(e1,e2,d1,d2)){y1=y;y2=i;d1=e1;d2=e2;}
	}
	cout<<y1<<' '<<y2<<endl;
	return 0;
}