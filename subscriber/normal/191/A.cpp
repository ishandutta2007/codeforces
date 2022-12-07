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

int n,f[500005],ans=0,q2[555555],q1[555555],co[555555],k,h[27];
char a[1111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d\n",&n);
	for (int i=0;i<n;i++){
		gets(a);
		k=strlen(a);
		co[i]=k;
		q1[i]=a[0]-'a';
		q2[i]=a[k-1]-'a';
	}
	for (int o=0;o<26;o++){
		memset(f,128,sizeof(f));
		memset(h,128,sizeof(h));
		for (int i=0;i<n;i++)if (q1[i]==o)f[i]=co[i];
		for (int i=0;i<n;i++){
			f[i]=max(f[i],co[i]+h[q1[i]]);
			h[q2[i]]=max(h[q2[i]],f[i]);
		}
		ans=max(ans,h[o]);
	}
	CC(ans);
	return 0;
}