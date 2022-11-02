#include <algorithm>
#include <stdio.h>
#include <memory.h>
#include <ctype.h>

using namespace std;

typedef long long INT;
typedef pair<int, int> pii;

#define NN 1100000

int N;
int t1[NN], t2[NN], t[NN];
int p[NN], pos[NN], pre[NN], nxt[NN];
int fix[NN];

void update1(int u, int val) {
	while (u<=N) {
		t1[u]=max(t1[u], val);
		u+=u&-u;
	}
}

int calc1(int u) {
	int res=0;
	while (u) {
		res=max(res, t1[u]);
		u-=u&-u;
	}
	return res;
}

void update2(int u, int val) {
	while (u<=N) {
		t2[u]=min(t2[u], val);
		u+=u&-u;
	}
}

int calc2(int u) {
	int res=N+1;
	while (u) {
		res=min(res, t2[u]);
		u-=u&-u;
	}
	return res;
}

int calc(int u) {
	int res=0;
	while (u) {
		res+=t[u];
		u-=u&-u;
	}
	return res;
}

void update(int u, int val) {
	while (u<=N) {
		t[u]+=val;
		u+=u&-u;
	}
}

int main() {
	int K, i, j, b;
	INT ans;
	
	scanf("%d%d", &N, &K);
	for (i=0; i<N; i++) scanf("%d", &p[i]);
	for (i=0; i<K; i++) {
		scanf("%d", &b);
		fix[b]=1;
	}
	
	for (i=0; i<N; i++) pos[p[i]]=i;
	
	for (i=0; i<N; i++) {
		if (fix[p[i]]) {
			update1(p[i], i+1);
		} else {
			pre[i]=calc1(p[i]);
		}
	}
	
	for (i=0; i<=N; i++) t2[i]=N+1;
	
	for (i=N-1; i>=0; i--) {
		if (fix[p[i]]) {
			update2(p[i], i+1);
		} else {
			nxt[i]=calc2(p[i])-1;
		}
	}
	
	for (i=1; i<=N; i++) {
		t[i]=(1<<__builtin_ctz(i));
	}
	ans=0;
	for (j=1; j<=N; j++) {
		if (fix[j]) continue;
		i=pos[j];
		ans+=calc(nxt[i])-calc(pre[i]);
		update(i+1, -1);
	}
	
	printf("%I64d\n", ans);
	
	return 0;
}