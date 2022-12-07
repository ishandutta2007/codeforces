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

int n,k,o,ans,a[111111];
long long b,oo,s,s1;
priority_queue<int>Q;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> k >> b;
	ans=n;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	for (int i=n-2;i>=0;i--){
		if (o<=k-1)s=oo;else s=s1;
		if (b-s1<a[i])ans=min(ans,i+1);
		o++;
		oo+=a[i];
		Q.push(-a[i]);
		s1+=a[i];
		if (Q.size()>k-1){
			s1+=Q.top();
			Q.pop();
		}
	}
	CC(ans);
	return 0;
}