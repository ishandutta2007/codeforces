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
const int B = 1<<20;
int n,m;

int a[2][N];
int T[B+B];
int M[B+B];
void print() {
	for(int i=0; i<B; i++) {
		int cur=i+B;
		int val=0;
		while(cur) val+=T[cur], cur/=2;
		printf("%d ", val);
	}
	printf("\n");
}
void add(int loc, int val) {
	int cur=1, L=0, R=B;
	while(R-L>1) {
		int mid=(L+R)/2;
		if(mid>loc) cur=cur+cur, R=mid;
		else {
			T[cur+cur]+=val;
			M[cur+cur]+=val;
			cur=cur+cur+1;
			L=mid;
		}
	}
	T[cur]+=val;M[cur]+=val;cur/=2;
	while(cur) M[cur]=max(M[cur+cur], M[cur+cur+1]) + T[cur], cur/=2;

/*	for(int t=1; t<=B; t=t+t) {
		for(int i=t; i<t+t; i++) printf("%d", M[i]);
		printf("\n");
	}*/
}
int find() {
	int cur=1;
	if(M[cur]<=0) return -1;
	int X=0;
	while(cur<B) {
		X+=T[cur];
		if(M[cur+cur+1]+X>0) cur=cur+cur+1;
		else cur=cur+cur;
	}
	return cur-B;
}
int main(void){
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d", a[0]+i);
	for(int i=1; i<=m; i++) scanf("%d", a[1]+i);
	for(int i=1; i<=n; i++) add(a[0][i],1);
	for(int i=1; i<=m; i++) add(a[1][i],-1);

	int q;
	scanf("%d", &q);
	while(q--) {
		int x, i, v;
		scanf("%d%d%d", &x, &i, &v); x--;
		int d=1-x-x;
		add(a[x][i], -d);
		add(v, d);
		a[x][i]=v;

		printf("%d\n", find());
//		print();
	}
}