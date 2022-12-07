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

int n,d,a[333333],u;
long long t,ans;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> d;
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	u=0;
	for (int i=2;i<n;i++){
		while (a[i]-a[u]>d)u++;
		if (u!=i){
			t=i-u;
			ans+=t*1ll*(t-1)/2;
		}
	}
	CC(ans);
	return 0;
}