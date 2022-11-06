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

int p[N];
int h(int cur) {
	if(p[cur]==cur) return cur;
	p[cur]=h(p[cur]);
	return p[cur];
}
int ans=0;
void merge(int x, int y) {
	x=h(x); y=h(y);
	if(x==y) return;
	p[y]=x; ans++;
}
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) p[i]=i;
	for(int i=0; i<m; i++) {
		int x,y;
		scanf("%d%d", &x, &y);
		merge(x,y);
	}
	printf("%d", m-ans);
}