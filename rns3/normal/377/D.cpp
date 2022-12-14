#include <bits/stdc++.h>
using namespace std;
#define M 300300

int n;
int L[M], R[M], V[M];

const int len = 300000;
int mx[M<<2];
int add[M<<2];
int rlt, LL, RR;

void push_up(int id) {
	mx[id] = max(mx[id<<1], mx[id<<1|1]);
}

void push_down(int id) {
	if (add[id]) {
		mx[id<<1] += add[id];
		mx[id<<1|1] += add[id];
		add[id<<1] += add[id];
		add[id<<1|1] += add[id];
		add[id] = 0;
	}
}

void update(int id, int st, int en, int a, int b, int v) {
	if (a <= st && en <= b) {
		mx[id] += v;
		add[id] += v;
		return;
	}
	push_down(id);
	int mid = st+en>>1;
	if (mid>=a) update(id<<1, st, mid, a, b, v);
	if (mid+1<=b) update(id<<1|1, mid+1, en, a, b, v);
	push_up(id);
}

int calc(int id, int st, int en) {
	if (st == en) {
		return st;
	}
	push_down(id);
	int mid = st+en>>1;
	if (mx[id<<1] >= mx[id<<1|1]) {
		return calc(id<<1, st, mid);
	}
	return calc(id<<1|1, mid+1, en);
}

vector<int> vl[M], vv[M];
int main() {
	//freopen("D3.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &L[i], &V[i], &R[i]);
		//printf("%d %d %d\n", L[i], V[i], R[i]);
		vl[L[i]].push_back(i);
		vv[V[i]].push_back(i);
	}

	for (int x = len; x >= 1; x--) {
      for (int i = 0; i < vv[x].size(); i++) {
			int j = vv[x][i];
			update(1, 1, len, V[j], R[j], 1);
      }
      if (rlt < mx[1]) {
			rlt = mx[1];
			LL = x;
			RR = calc(1, 1, len);
      }
      for (int i = 0; i < vl[x].size(); i++) {
			int j = vl[x][i];
			update(1, 1, len, V[j], R[j], -1);
      }
	}

   printf("%d\n", rlt);
   //printf("LL = %d, RR = %d\n", LL, RR);
   for (int i = 1; i <= n; i++) {
	//printf("%d %d %d\n", L[i], V[i], R[i]);
   }
   for (int i = 1; i <= n; i++) if (L[i] <= LL && R[i] >= RR && LL <= V[i] && V[i] <= RR) {
   		//printf("~~%d %d %d %d\n", L[i], LL, RR, R[i]);
		printf("%d ", i);
   }
   puts("");
	return 0;
}