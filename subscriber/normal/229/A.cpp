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

int n,m,ans=1e9;
char a[111111];
set<int>s[111];
set<int>::iterator it;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%d%d\n",&n,&m);
	for (int i=0;i<n;i++){
		gets(a);
		for (int j=0;j<m;j++)if (a[j]=='1')s[i].insert(j),s[i].insert(j+m),s[i].insert(j+m+m);
		if (s[i].size()==0){
			puts("-1");
			return 0;
		}
	}
	for (int i=0;i<m;i++){
		int ss=0;
		for (int j=0;j<n;j++){
			it=s[j].lower_bound(i+m);
			int h=abs(m+i-(*it));
			it--;
			h=min(h,abs(m+i-(*it)));
			ss+=h;
		}
		ans=min(ans,ss);
	}
	CC(ans);
	return 0;
}