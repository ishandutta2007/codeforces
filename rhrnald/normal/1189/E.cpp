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
int n,p,k;
ll x[N];
int main(void){
	scanf("%d%d%d", &n, &p, &k);
	for(int i=0; i<n; i++) scanf("%lld", x+i);
	for(int i=0; i<n; i++) {
		ll t=x[i]*x[i]%p;
		t=t*t%p;
		t-=k*x[i];
		x[i]=(t%p+p)%p;
	}
	sort(x, x+n);
	int cur=0;
	ll ans=0;
	while(cur<n) {
		int t=cur;
		while(cur<n && x[cur] == x[t]) cur++;
		ll tt=cur-t;
		ans+=tt*(tt-1)/2;
	}
	printf("%lld", ans);
}