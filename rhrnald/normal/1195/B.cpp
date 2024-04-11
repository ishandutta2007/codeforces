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
ll n,m;

int main(void){
	scanf("%lld%lld", &n, &m);
	ll l=0, r=INF;
	while(r-l>1) {
		ll mid=(r+l)/2;
		if(1ll*mid*mid+3ll*mid<=m+m+n+n) l=mid;
		else r=mid;
	}
	cout << n-l;
}