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

char a[1111111];
int n,f[1111111][2],p[1111111][2],x;


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	gets(a);
	n=strlen(a);
	reverse(a,a+n);
	m1(f);
	f[0][0]=0;
	for (int i=0;i<n;i++){	
			if (a[i]=='1'){
				if (f[i][1]<f[i+1][1])f[i+1][1]=f[i][1],p[i+1][1]=1;
			}else{
				if (f[i][1]+1<f[i+1][0])f[i+1][0]=f[i][1]+1,p[i+1][0]=1;
				if (f[i][1]+1<f[i+1][1])f[i+1][1]=f[i][1]+1,p[i+1][1]=1;
			}
			if (a[i]=='0'){
				if (f[i][0]<f[i+1][0])f[i+1][0]=f[i][0],p[i+1][0]=0;
			}else{
				if (f[i][0]+1<f[i+1][0])f[i+1][0]=f[i][0]+1,p[i+1][0]=0;
				if (f[i][0]+1<f[i+1][1])f[i+1][1]=f[i][0]+1,p[i+1][1]=0;
			}
	}
	CC(min(f[n][0],f[n][1]+1));
	if (f[n][0]<f[n][1]+1)x=0;else x=1;
	if (x)printf("+2^%d\n",n);
	for (int i=n;i>0;i--){
		if (x!=p[i][x]){
			if (x)printf("-2^%d\n",i-1);else printf("+2^%d\n",i-1);
		}else if (x&&a[i-1]=='0')printf("-2^%d\n",i-1);else if (!x&&a[i-1]=='1')printf("+2^%d\n",i-1);
		x=p[i][x];
	}
	return 0;
}