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

int n,a[111111],p[44],b[44],w[5000555];
long long ans;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i],a[i]+=pw(21);
	for (int i=0;i<23;i++)p[i]=-1;
	for (int i=n-1;i>=0;i--){
		for (int j=0;j<23;j++)if (a[i]&pw(j))p[j]=i;
		for (int j=0;j<23;j++)b[j]=p[j];
		sort(b,b+23);
		int t=0;
		for (int j=1;j<23;j++)if (b[j]!=-1){
			t|=a[b[j]];
			if (!w[t])ans++;
			w[t]=1;
		}
	}
	CC(ans);
	return 0;
}