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

long long d[311111],s,z,x;
char a[311111],b[311111];
int n;
long double aa=0;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d\n",&n);
	gets(a);
	gets(b);
	for (int i=0;i<n;i++)z+=(n-i)*1ll*(n-i);
	for (int o='A';o<='Z';o++){
		m0(d);
		for (int i=0;i<n;i++)if (a[i]==o)d[0]+=(n-i),d[i+1]-=(n-i)+i+1;
		s=0;
		x=0;
		for (int i=0;i<n;i++){
			s+=d[i];
			x+=s;
			if (b[i]==o)aa+=x/1./z;
		}
	}
	printf("%.9lf\n",(double)aa);
	return 0;
}