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
const ll MOD = 998244353;

const int N = 1000001;
int n,m,x,y;
int d[N];

ll f[N];
int main(void){
	scanf("%d", &n);
	f[0]=1;
	for(int i=1; i<211111; i++) f[i]=f[i-1]*i%MOD;
	for(int i=1; i<n; i++) {scanf("%d%d", &x, &y); d[x]++, d[y]++;}

	ll ans=n;
	for(int i=1; i<=n; i++) {
		ans=ans*f[d[i]]%MOD;
	}
	cout << ans;
}