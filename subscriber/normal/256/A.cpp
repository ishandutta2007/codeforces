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

int n,a[5555],f[4444][4444],b[4444],q[1000111],ans=0,s[1000111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<=1000000;i++)q[i]=n;
	for (int i=n-1;i>=0;i--)b[i]=q[a[i]],q[a[i]]=i,s[a[i]]++;
	for (int i=0;i<=1000000;i++)ans=max(ans,s[i]);
	for (int i=0;i<n;i++)for (int j=i+1;j<n;j++)if (a[i]!=a[j])f[i][j]=2;
	for (int i=0;i<n;i++){
		int x=b[i];
		for (int j=i+1;j<n;j++)if (a[i]!=a[j]){
	                while (x<j)x=b[x];
			if (x!=n)f[j][x]=max(f[j][x],f[i][j]+1);
		}
	}
	for (int i=0;i<n;i++)for (int j=0;j<n;j++)ans=max(ans,f[i][j]);
	CC(ans);
	return 0;
}