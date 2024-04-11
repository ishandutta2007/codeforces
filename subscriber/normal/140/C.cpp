#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;

int n,x;
map<int,int>m;
map<int,int>::iterator it;
priority_queue<pair<int,int> >Q;
pair<int,int>t1,t2,t3;
vector<pair<pair<int,int>,int> >ans;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		scanf("%d",&x);
		m[x]++;
	}
	for (it=m.begin();it!=m.end();it++)Q.push(mp((*it).second,(*it).first));
	for(;;){
		if (Q.size()<3)break;
		t1=Q.top();
		Q.pop();
		t2=Q.top();
		Q.pop();
		t3=Q.top();
		Q.pop();
		vector<int>v;
		v.pb(t1.S);
		v.pb(t2.S);
		v.pb(t3.S);
		sort(v.begin(),v.end());
		ans.pb(mp(mp(v[2],v[1]),v[0]));
		if (t1.F>1)Q.push(mp(t1.F-1,t1.S));
		if (t2.F>1)Q.push(mp(t2.F-1,t2.S));
		if (t3.F>1)Q.push(mp(t3.F-1,t3.S));
	}
	CC(ans.size());
	for (int i=0;i<ans.size();i++)printf("%d %d %d\n",ans[i].F.F,ans[i].F.S,ans[i].S);
	return 0;
}