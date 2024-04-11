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
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

string s,ss;
int k,n,o[111111];
long long q,ans,f[111111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> s >> ss >>k;
	n=s.size();
	s+=s;
	for (int i=0;i<n;i++)o[i]=s.substr(i,n)==ss;
	f[0]=1;
	for (int it=0;it<k;it++){
		q=0;
		for (int i=0;i<n;i++)q+=f[i];
		for (int i=0;i<n;i++)f[i]=(q-f[i])%M;
	}
	for (int i=0;i<n;i++)if (o[i])ans=(ans+f[i])%M;
	CC(ans);
	return 0;
}