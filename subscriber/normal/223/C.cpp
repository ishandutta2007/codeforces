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
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n,k,a[2222],r[2222],ans[2222],c[2222];

void mm0(){
	m0(c);
	for (int i=0;i<n;i++)for (int j=i;j<n;j++)c[j]=(c[j]+r[i]*1ll*r[j-i])%M;
	for (int i=0;i<n;i++)r[i]=c[i];
}

void mm1(){
	m0(c);
	for (int i=0;i<n;i++)for (int j=i;j<n;j++)c[j]=(c[j]+r[i])%M;
	for (int i=0;i<n;i++)r[i]=c[i];
}

void gg(int x){
	if (!x)return;
	gg(x/2);
	mm0();
	if (x%2)mm1();
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k;
	for (int i=0;i<n;i++)cin >> a[i];
	r[0]=1;
	gg(k);
	for (int i=0;i<n;i++)for (int j=i;j<n;j++)ans[j]=(ans[j]+a[i]*1ll*r[j-i])%M;
	for (int i=0;i<n-1;i++)cout << ans[i] << " ";
	CC(ans[n-1]);
	return 0;
}