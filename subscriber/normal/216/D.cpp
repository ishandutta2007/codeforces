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

int n,k[111111],x,y,xx,yy,ans;
vector<int>a[111111];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++){
		scanf("%d",&k[i]);
		a[i].resize(k[i]);
		for (int j=0;j<k[i];j++)scanf("%d",&a[i][j]);
		sort(a[i].begin(),a[i].end());
	}
	for (int i=0;i<n;i++){
		x=(i-1+n)%n;
		y=(i+1)%n;
		for (int j=1;j<k[i];j++){
			xx=upper_bound(a[x].begin(),a[x].end(),a[i][j])-lower_bound(a[x].begin(),a[x].end(),a[i][j-1]);
			yy=upper_bound(a[y].begin(),a[y].end(),a[i][j])-lower_bound(a[y].begin(),a[y].end(),a[i][j-1]);
			if (xx!=yy)ans++;
		}
	}
	CC(ans);
	return 0;
}