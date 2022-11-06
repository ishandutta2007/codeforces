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
deque<int> dq;

int a[N], b[N];
int ans[N];
int lim;
int c[N];
int main(void){
	scanf("%d%d", &n, &m);
	int M=-1;
	for(int i=0;i<n;i++) {
		int x;
		scanf("%d", &x);
		M=max(x, M);
		dq.push_back(x);
	}

	while(dq.front()<M) {
		a[lim]=dq.front(); dq.pop_front();
		b[lim]=dq.front(); dq.pop_front();
		dq.push_front(max(a[lim], b[lim]));
		dq.push_back(min(a[lim], b[lim]));
		lim++;
	}
	dq.pop_front();
	for(int i=0; i<n-1; i++) {
		c[i]=dq.front(); dq.pop_front();
	}

	for(int i=0; i<m; i++) {
		ll x;
		scanf("%lld", &x);x--;
		if(x<lim) printf("%d %d\n", a[x], b[x]);
		else printf("%d %d\n", M, c[(x-lim)%(n-1)]);
	}
}