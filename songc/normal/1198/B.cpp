#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, Q;
pii A[202020];
int Max[808080]; 

void update(int id, int s, int e, int t, int v){
	if (e < t || t < s) return;
	if (s == e){
		Max[id] = v;
		return;
	}
	int mid = (s+e)/2;
	update(id*2, s, mid, t, v);
	update(id*2+1, mid+1, e, t, v);
	Max[id] = max(Max[id*2], Max[id*2+1]);
}

int RMQ(int id, int s, int e, int ts, int te){
	if (e < ts || te < s) return 0;
	if (ts <= s && e <= te) return Max[id];
	int mid = (s+e)/2;
	return max(RMQ(id*2, s, mid, ts, te), RMQ(id*2+1, mid+1, e, ts, te));
}

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++) scanf("%d", &A[i].first);
	scanf("%d", &Q);
	for (int i=1; i<=Q; i++){
		int x, y;
		scanf("%d", &x);
		if (x == 1){
			scanf("%d %d", &x, &y);
			A[x] = pii(y, i);
		}
		else {
			scanf("%d", &x);
			update(1, 1, Q, i, x);
		}
	}
	for (int i=1; i<=N; i++) printf("%d ", max(A[i].first, RMQ(1, 1, Q, A[i].second+1, Q)));
	printf("\n");
	return 0;
}