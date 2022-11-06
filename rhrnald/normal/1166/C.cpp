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
int n,m;
int x[N];
int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", x+i);
	for(int i=0; i<n; i++) x[i]=abs(x[i]);
	sort(x, x+n);
	ll ans=0;
	for(int i=0; i<n; i++) {
		ans+=upper_bound(x, x+n, x[i]+x[i])-(x+i+1);
	}
	cout << ans;
}