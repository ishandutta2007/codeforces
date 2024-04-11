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
int n;
ll m;
vector<int> v;
void make() {
	for(int i=2; i*i<=n; i++) {
		if(!(n%i)) {
			v.push_back(i);
			while(!(n%i)) n/=i;
		}
	}
	if(n>1) v.push_back(n);
}
const int MOD=1000000007;
#define mult(x, y) ((1ll*x*y)%MOD)
ll pow(int p, ll c) {
	if(c==0) return 1;
	if(c==1) return p;
 
	ll t=pow(p, c/2);
	if(c&1) return mult(mult(t,t),p);
	else return mult(t,t);
}
ll f(int p) {
	ll mm=m;
	ll cnt=0;
	while(mm) mm/=p, cnt+=mm;
	return pow(p, cnt);
}
int main(void){
	scanf("%d%lld", &n, &m);
	make();
	ll ans=1;
	for(int e : v) ans=mult(ans, f(e));
	printf("%lld", ans);
}