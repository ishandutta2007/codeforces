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
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int n,o,x;
map<string,int>m;
map<string,int>::iterator it;
vector<pair<string,int> >e;
string s;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> s >> x;
		m[s]=max(m[s],x);
	}
	for (it=m.begin();it!=m.end();it++)e.pb(*it);
	o=e.size();
	CC(o);
	for (int i=0;i<e.size();i++){
		int a=0,b=0;
		for (int j=0;j<e.size();j++)if (e[j].S>e[i].S)a++;else b++;
		cout << e[i].F << " ";
		if (b*100>=o*99)puts("pro");else
		if (b*100>=o*90)puts("hardcore");else
		if (b*100>=o*80)puts("average");else
		if (b*100>=o*50)puts("random");else puts("noob");
	}
	return 0;
}