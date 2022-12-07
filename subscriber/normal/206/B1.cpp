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

int n,a[11111],f[11111],o,z[111111],h[11111];
long long ans=0;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=0;i<n;i++){
		f[0]=0;
		z[0]=0;
		h[0]=0;
		o=1;
		for (int j=1;j<n;j++){
			int t;
			for (int l=o-1;l>=0;l--)if (h[l]>=j-a[j])t=l;else break;
			f[j]=z[t]+1;
			while (o>0&&z[o-1]>=f[j])o--;
			z[o]=f[j];
			h[o++]=j;
		}
		ans+=f[n-1];
		int g=a[n-1];
		for (int j=n-1;j;j--)a[j]=a[j-1];
		a[0]=g;
	}
	CC(ans);
	return 0;
}