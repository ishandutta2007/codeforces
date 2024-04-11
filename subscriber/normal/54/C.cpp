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

long long n,x,y,k;
long double a[1111],ans=0,f[1111][1111];

long long sl(long long x){
	SS q,qq;
	q<<x;
	string s=q.str();
	long long ret=0,a;
	if (s=="1")ret++;else
	if (s[0]=='1'){
		qq<<s.substr(1,s.size()-1);
		qq>>a;
		ret+=a+1;
	}
	for (int i=0;i<s.size();i++)if (s[i]>'1'||i){
		a=1;
		for (int j=i+1;j<s.size();j++)a*=10;
		ret+=a;
	}
	return ret;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> x >> y;
		a[i]=(sl(y)-sl(x-1))/1./(y-x+1);
	}
	cin >> k;
	f[0][0]=1;
	for (int i=0;i<n;i++)for (int j=0;j<=n;j++){
		f[i+1][j+1]+=f[i][j]*a[i];
		f[i+1][j]+=f[i][j]*(1-a[i]);
	}
	for (int i=0;i<=n;i++)if (100.*i/n+1e-11>k)ans+=f[n][i];
	cout.precision(10);
	cout << fixed << ans << endl;
	return 0;
}