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

const int N = 1001;
int n,m;
int c;
vector<int> v[N];

int p[N];
int cnt[N];
int dfs(int x) {
	cnt[x]=1;
	for(int e : v[x]) {
		if(!p[e]) p[e]=x, cnt[x]+=dfs(e);
	}
	return cnt[x];
}
void make(int x) {
	for(int i=1; i<=n; i++) p[i]=0;
	p[x]=x;
	dfs(x);
}
int find() {
	make(1);
	int cur=1;
	while(true) {
		bool flag=true;
		for(int e : v[cur]) {
			if(p[cur]==e) continue;
			if(cnt[e]>n/2) {cur=e;flag=false;break;}
		}
		if(flag) return cur;
	}
}

int L[N];
int cur;
vector<int> v1, v2;
void dfs2(int x, int d) {
	L[x]=cur; cur+=d;
	printf("%d %d %d\n", p[x], x, L[x]-L[p[x]]);

	for(int e : v[x]) {
		if(e!=p[x]) dfs2(e, d);
	}
}
void fin() {
	cur=1;
	for(int e : v1) dfs2(e, 1);
	
	int d=cur;
	for(int e : v2) {
		dfs2(e, d);
	}
}
int main(void){
	scanf("%d", &n);
	for(int i=1; i<n; i++) {
		int x,y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	c=find();
	make(c);
	int bound=(n+2)/3;
	for(int e: v[c]) {
		if(cnt[e]>=bound) {
			v1.push_back(e);
			for(int t: v[c]) if(t!=e) v2.push_back(t);
			fin();
			return 0;
		}
	}
	
	int sum=0;
	for(int e : v[c]) {
		if(sum<bound) {
			v1.push_back(e);
			sum+=cnt[e];
		} else {
			v2.push_back(e);
		}
	}
	fin();
}