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

int n,k,a[111],g[111],f[111],o,A[111],B[111],aa,bb,m,x;
string s;

int main(){
	freopen("input.txt","r",stdin);	
	freopen("output.txt","w",stdout);	
	cin >> m >> k;
	for (int i=0;i<k;i++)cin >> a[i],g[a[i]]=1;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> s;
		cin >> k;
		m0(f);
		o=0;
		for (int j=0;j<k;j++){
			cin >> x;
			f[x]=1;
			if (g[x])A[i]++,B[i]++;
			if (x==0)o++;
		}
		int oo=o;
		for (int j=1;j<=m;j++)if (oo>0&&g[j]==0&&f[j]==0)oo--;
		A[i]+=oo;
		for (int j=1;j<=m;j++)if (o>0&&g[j]&&f[j]==0){
			o--;   
			B[i]++;
		}
	}
	for (int i=0;i<n;i++){
		aa=bb=-1;
		for (int j=0;j<n;j++)if (j!=i)bb=max(bb,B[j]),aa=max(aa,A[j]);
		if (A[i]>=bb)CC(0);else if (B[i]<aa)CC(1);else CC(2);
	}
	return 0;

}