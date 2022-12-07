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

int n,k,m,a[1111],x,f[1111],ans=1e9;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k >> m;
	for (int i=0;i<m;i++){
		cin >> x;
		a[x]=1;
	}
	m1(f);
	f[0]=0;
	for (int i=0;i<n;i++){
		for (int j=i+1;j<=n;j++){
			f[j]=min(f[j],f[i]+1);
			if (a[j]||j-i==k)break;
		}
	}
	for (int i=0;i<min(k,n);i++){
		ans=min(ans,f[n-i]);
		if (a[n-i])break;
	}
	CC(ans);
	return 0;
}