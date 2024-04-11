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

string e[7]={"Anka","Chapay","Cleo","Troll","Dracul","Snowy","Hexadecimal"},s1,s2,s;
int n,ans1=999999999,ans2,aa,bb,cc;
map<pair<string,string>,int>o;
vector<string>a,b,c;

void check(){
	int t=0;
	if (a.empty()||b.empty()||c.empty())return;
	int m1=min(aa/a.size(),min(bb/b.size(),cc/c.size()));
	int m2=max(aa/a.size(),max(bb/b.size(),cc/c.size()));
	for (int i=0;i<a.size();i++)for (int j=0;j<a.size();j++)t+=o[mp(a[i],a[j])];
	for (int i=0;i<b.size();i++)for (int j=0;j<b.size();j++)t+=o[mp(b[i],b[j])];
	for (int i=0;i<c.size();i++)for (int j=0;j<c.size();j++)t+=o[mp(c[i],c[j])];
	if (m2-m1<ans1||m2-m1==ans1&&t>ans2)ans1=m2-m1,ans2=t;
}

void rec(int l){
	if (l==7){
		check();
		return;
	}
	a.pb(e[l]);
	rec(l+1);
	a.pop_back();
	b.pb(e[l]);
	rec(l+1);
	b.pop_back();
	c.pb(e[l]);
	rec(l+1);
	c.pop_back();
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> s1 >> s >> s2;
		o[mp(s1,s2)]=1;
	}
	cin >> aa >> bb >> cc;
	rec(0);
	cout << ans1 << " " << ans2 << endl;
	return 0;
}