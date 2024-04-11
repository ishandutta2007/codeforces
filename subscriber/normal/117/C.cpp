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

char a[5555][5555];
int n;

void solve(vt e){
	if (e.size()<3)return;
	vt s1,s2;
	for (int i=1;i<e.size();i++)if (a[e[0]][e[i]]=='1')s1.pb(e[i]);else s2.pb(e[i]);
	for (int i=0;i<s1.size();i++)for (int j=0;j<s2.size();j++)if (a[s1[i]][s2[j]]=='1'){
		printf("%d %d %d\n",e[0]+1,s1[i]+1,s2[j]+1);
		exit(0);
	}
	solve(s1);
	solve(s2);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d\n",&n);
	for (int i=0;i<n;i++)gets(a[i]);
	vt l;
	for (int i=0;i<n;i++)l.pb(i);
	solve(l);
	puts("-1");
	return 0;
}