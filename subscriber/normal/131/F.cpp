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

int n,m,k,w[555][555],e[555][555];
long long ans=0;
char a[555][555];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d%d\n",&n,&m,&k);
	for (int i=0;i<n;i++)gets(a[i]);
	for (int i=0;i<n;i++)for (int j=0;j<m;j++)a[i][j]-='0';
	for (int i=1;i<n-1;i++)for (int j=1;j<m-1;j++)if (a[i][j]+a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1]==5)w[i][j]=1;
	for (int i=1;i<n;i++)for (int j=1;j<m;j++)e[i][j]=e[i-1][j]+e[i][j-1]-e[i-1][j-1]+w[i][j];
	for (int a=1;a<n-1;a++)for (int b=a;b<n-1;b++){
		int l=1,r=1;
		while (r<m-1){
			if (e[b][r]-e[a-1][r]-e[b][l-1]+e[a-1][l-1]>=k){
				ans+=(m-r-1);
				l++;
			}else r++;
		}
	}
	CC(ans);
	return 0;
}