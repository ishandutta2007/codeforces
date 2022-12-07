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
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

long long a[4],n,ans=0;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> n;
	for (int o=1;o<16;o++){
		long long e=1,t=0;
		for (int i=0;i<4;i++)if (o&pw(i)){
			t^=1;
			e=a[i]/__gcd(e,a[i])*e;
		}
		if (t)ans+=n/e;else ans-=n/e;
	}
	CC(ans);
	return 0;
}