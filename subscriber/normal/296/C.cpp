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

int n,k,m,x[555555],y[555555],a[555555],z[555555],xx,yy;
long long s[555555],ss[555555];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> k;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=0;i<m;i++)scanf("%d%d%d",&x[i],&y[i],&z[i]);
	for (int i=0;i<k;i++){
		scanf("%d%d",&xx,&yy);
		s[xx-1]++;
		s[yy]--;
	}
	for (int i=1;i<m;i++)s[i]+=s[i-1];
	for (int i=0;i<m;i++)ss[x[i]-1]+=s[i]*z[i],ss[y[i]]-=s[i]*z[i];
	for (int i=1;i<n;i++)ss[i]+=ss[i-1];
	for (int i=0;i<n;i++)cout << a[i]+ss[i] << " ";
	return 0;
}