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
#include<cstring>
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
#define N 211111
using namespace std;
typedef pair<int,int> pt;

long long f(long long n, int b, int o) {
	long long k = n / b;
	if (n % b != 0 && n % b >= o) k++;
	if (k == 0) return 0;
	return (o + o + b * (k - 1)) * k / 2;
}

long long pv(long long a, long long b) {	
	if (b == 0) return 1;
	long long r = pv(a, b / 2);
	r = r * r % M;
	if (b % 2) r = r * a % M;
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	long long a, b;
	cin >> a >> b;
	long long ans = 0;
	int dd = pv(2, M -2);
	for (int i = 1; i < b; i++) {
		int o = i;

		long long f = (o + b * o) % M;
		long long last = (o + b * a % M * o) % M;


		long long add = (f + last) * a % M;
		add = add * dd % M;
		ans += add;
		if (ans >= M) ans -= M;

	}
	cout << ans << endl;
	return 0;
}