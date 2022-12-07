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
#define M 1000000007

long long f[2222][2222],s[2222][2222],ss;
int n,m,k;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> k;
	for (int i=1;i<1111;i++)f[0][i]=1;
	for (int i=1;i<1111;i++)s[0][i]=i;
	for (int o=1;o<=k;o++){
		ss=0;
		for (int i=3;i<1111;i++){
			ss=(ss+s[o-1][i-2])%M;
			f[o][i]=ss;
		}
		for (int i=1;i<1111;i++)s[o][i]=(s[o][i-1]+f[o][i])%M;
	}
	CC(f[k][n]*f[k][m]%M);
	return 0;
}