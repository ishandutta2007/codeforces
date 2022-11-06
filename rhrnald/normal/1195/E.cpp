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

const int N = 3010;
int n,m,a,b;
ll t,x,y,z;

int p[N][N];
int B=1;
void print() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			printf("%d ", p[i][j]);
		printf("\n");
	}
}
deque<pii> v;
int main(void){
	scanf("%d%d%d%d", &n, &m, &a, &b);
	while(B<n || B<m) B<<=1;
	scanf("%lld%lld%lld%lld", &t, &x, &y, &z);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			p[i][j]=t;
			t=(t*x+y)%z;
		}
	for(int i=0; i<n; i++) {
		v.clear();
		for(int j=0; j<b; j++) {
			while(!v.empty() && v.back().first>=p[i][j]) v.pop_back();
			v.push_back({p[i][j], j});
		}

		p[i][0]=v.front().first;

		for(int j=0; j+b<m; j++) {
			while(!v.empty() && v.front().second<=j) v.pop_front();
			while(!v.empty() && v.back().first>=p[i][j+b]) v.pop_back();
			v.push_back({p[i][j+b], j+b});
			p[i][j+1]=v.front().first;
		}
	}
	for(int j=0; j+b<=m; j++) {
		v.clear();
		for(int i=0; i<a; i++) {
			while(!v.empty() && v.back().first>=p[i][j]) v.pop_back();
			v.push_back({p[i][j], i});
		}

		p[0][j]=v.front().first;

		for(int i=0; i+a<n; i++) {
			while(!v.empty() && v.front().second<=i) v.pop_front();
			while(!v.empty() && v.back().first>=p[i+a][j]) v.pop_back();
			v.push_back({p[i+a][j], i+a});
			p[i+1][j]=v.front().first;
		}
	}

	ll ans=0;
	for(int i=0; i+a<=n; i++)
		for(int j=0; j+b<=m; j++) {
			ans+=p[i][j];
		}
	cout << ans;
}