#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 1000001;
const int MOD=1000000007;
int n,m;
#define mult(x,y) (1ll*(x)*(y)%MOD)
ll p(ll x, ll c) {
	if(c==0) return 1;
	if(c==1) return x;
	ll t=p(x,c/2);
	if(c&1) {
		return mult(mult(t, t), x);
	} else {
		return mult(t,t);
	}
}
int main(void){
	scanf("%d%d", &n, &m);
	printf("%lld", p(p(2, m)-1, n));
}