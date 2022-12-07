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

int x,y;
long long ans,n,m,v[1000111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		x--;
		y--;
		v[x]++;
		v[y]++;
	}
	ans=n*1ll*(n-1)*1ll*(n-2)/6;
	ans-=m*1ll*(n-2);
	for (int i=0;i<n;i++)ans+=v[i]*1ll*(v[i]-1)/2;
	CC(ans);
	return 0;
}