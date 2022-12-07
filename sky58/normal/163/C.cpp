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
typedef pair<double,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int ch[110000];
double out[110000];
double cal(double a,double b){
	return max(0.0,a-b);
}
int main()
{
	int n,l,v1,v2,i,now=0;double a;
	vector <pint> d;
	cin>>n>>l>>v1>>v2;
	double len=1.0*l*v2/(v1+v2);
	rep(i,110000) out[i]=0.0;
	rep(i,n) scanf("%d",&ch[i]);
//	rep(i,n) cout<<ch[i]<<endl;
	for(i=n-1;i>=0;i--) ch[i]-=ch[0];
//	rep(i,n) cout<<ch[i]<<endl;
	rep(i,n){
		a=0.0+ch[i];
		scanf("%f",&a);d.pb(mp(a,-1));
		if(a>len) d.pb(mp(a-len,1));
		else{d.pb(mp(a+2.0*l-len,1));now++;}
	}
	d.pb(mp(2.0*l,0));
	sort(All(d));
//	rep(i,2*n) cout<<d[i].fi<<' '<<d[i].se<<endl;
	rep(i,2*n){
		now+=d[i].se;out[now]+=d[i+1].fi-d[i].fi;
	}
/*	int t1=0,t2=0,now=0;
	rep(t1,n){
		now--;
		while(1){
			if(ch[t2-1]-ch[t1+1]>len) break;
			out[now]+=max(0.0,cal(ch[t2]-ch[t1],len)-cal(ch[t2-1]-ch[t1],len)-cal(ch[t2]-ch[t1+1],len));
			t2++;now++;//if(ch[t2-1]-ch[t1+1]>len) break;
		}
	}
*/	rep(i,n+1){
		printf("%.12f\n",out[i]*0.5/l);
	}
	return 0;
}