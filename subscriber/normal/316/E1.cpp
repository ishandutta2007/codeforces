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
#define M 1000000000
using namespace std;
typedef pair<int,int> pt;

int n,m,a[211111],f[211111],x,y,t;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m;
	for (int i=0;i<n;i++)cin >> a[i];
	f[0] = f[1] = 1;
	for (int i=2;i<=n;i++)f[i] = (f[i-1] + f[i-2])%M;
	for (int i=0;i<m;i++){
		cin >> t;
		if (t == 1){
			cin >> x >> y;
			x--;
			a[x] = y;
		}else {
			long long ans=0;
			cin >> x >> y;
			x--;
			y--;
			for (int i=x;i<=y;i++)ans=(ans+a[i]*1ll*f[i-x])%M;
			cout << ans << endl;
		}
	}
	return 0;
}