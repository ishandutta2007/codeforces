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
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
#define M 1000000007

int n,k,g,a[111111],e=0;
long long ans=0,x,f[2222][2222],ff[111111];
vt v;
map<int,int>m;
map<int,int>::iterator it;

long long pv(int a,int b){
	if (!b)return 1;
	long long r=pv(a,b/2);
	r=r*r%M;
	if (b%2)r=r*a%M;
	return r;
}

bool oo(int x){
	while (x){
		if (x%10!=4&&x%10!=7)return 0;
		x/=10;
	}
	return 1;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++)if (oo(a[i]))m[a[i]]++;else e++;
	for (it=m.begin();it!=m.end();it++)v.pb((*it).S);
	ff[0]=1;
	for (int i=1;i<=n;i++)ff[i]=ff[i-1]*i%M;
	g=v.size();
	f[0][0]=1;
	for (int i=0;i<g;i++)for (int j=0;j<=g;j++){
		f[i+1][j]=(f[i+1][j]+f[i][j])%M;
		f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*v[i])%M;
	}
	for (int i=0;i<=g;i++)if (i<=k&&k-i<=e){
		x=ff[e];
		x=x*pv(ff[k-i],M-2)%M;
		x=x*pv(ff[e-(k-i)],M-2)%M;
		ans=(ans+f[g][i]*x)%M;
	}
	CC(ans);
	return 0;
}