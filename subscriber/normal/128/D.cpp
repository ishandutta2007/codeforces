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

int a[111111],b[111111],n,k=0,x;

void er(){
	puts("NO");
	exit(0);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	sort(a,a+n);
	for (int i=1;i<n;i++)if (a[i]-a[i-1]>1)er();
	b[k++]=1;
	for (int i=1;i<n;i++)if (a[i]!=a[i-1]){
		b[k++]=1;
	}else b[k-1]++;
	if (k==1)er();
	b[0]--;
	b[k-1]--;
	for (int i=1;i<k-1;i++)if (b[i]<2)er();else b[i]-=2;
	for (int i=1;i<k;i++){
		x=min(b[i],b[i-1]);
		b[i]-=x;
		b[i-1]-=x;
	}
	for (int i=0;i<k;i++)if (b[i])er();
	puts("YES");	
	return 0;
}