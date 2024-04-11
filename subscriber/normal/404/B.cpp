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
#define pw(x) (1ll<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	long double a1, d1;
	int n;
	cin >> a1 >> d1;
	long long a = a1 * 10000 + 1e-9;
	long long d = d1 * 10000 + 1e-9;

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x = 1ll * (i + 1) * d % (4 * a);
		long long xx, yy;
		if (x < a) {
			xx = x;
			yy = 0;
		} else if (x < a + a) {
			xx = a;
			yy = x - a;
		} else if (x < a + a + a) {
			xx = a + a + a - x;
			yy = a;
		} else {
			xx = 0;
			yy = a + a + a + a - x;
		}
		printf("%.8lf %.8lf\n", xx / 10000., yy / 10000.);
	}
	return 0;
}