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

int ans,n,m,a[2111111],b[2111111],bb[2111111],s,l,r,o,e[2111111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=0;i<m;i++)scanf("%d",&b[i]);
	for (int i=0;i<n;i++)a[i+n]=a[i];
	for (int i=0;i<m;i++)bb[b[i]]=i+1;
	for (int i=0;i<n+n;i++){
		s=bb[a[i]];
		if (!s){
			l=r=o=0;
			continue;
		}
		e[++r]=s;
		if (r-l>1&&e[r]<=e[r-1])o++;
		while (o>1||o&&e[r]>=e[l+1]){
			if (e[l+1]>e[l+2])o--;
			l++;
		}
		ans=max(ans,r-l);
	}
	CC(ans);
	return 0;
}