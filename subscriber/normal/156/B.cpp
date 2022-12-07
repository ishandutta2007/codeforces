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

int n,m,x[111111],a[111111],b[111111],aa,bb,e,f[111111];
char o[111111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d\n",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%c%d\n",&o[i],&x[i]);
		x[i]--;
		if (o[i]=='+')a[x[i]]++,aa++;else b[x[i]]++,bb++;
	}
	for (int i=0;i<n;i++)if (a[i]+bb-b[i]==m){
		f[i]=1;
		e++;
	}
	for (int i=0;i<n;i++){
		if (o[i]=='+'&&f[x[i]]&&e==1)puts("Truth");else
		if (o[i]=='+'&&f[x[i]])puts("Not defined");else
		if (o[i]=='+')puts("Lie");
		if (o[i]=='-'&&f[x[i]]==0)puts("Truth");else
		if (o[i]=='-'&&f[x[i]]&&e>1)puts("Not defined");else
		if (o[i]=='-')puts("Lie");
	}
	return 0;
}