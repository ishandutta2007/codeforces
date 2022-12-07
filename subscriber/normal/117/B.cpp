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

int a,b,mod,o,d;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> a >> b >> mod;
	o=min(a,mod-1);
	d=1000000000%mod;
	for (int i=0;i<=o;i++)if ((mod-i*1ll*d%mod)%mod>b){
		SS q;
		q<<i;
		string s=q.str();
		while (s.size()<9)s="0"+s;
		cout << "1 " << s << endl;
		return 0;
	}
	puts("2");
	return 0;
}