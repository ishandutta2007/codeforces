#include <cstdio>
#define left (i<<1)
#define right (i<<1|1)
#define max(a, b) (a) > (b) ? (a) : (b)
#define pull\
	sum[i] = sum[left] + sum[right];\
	maxv[i] = max(maxv[left], maxv[right])
using namespace std;
const int MAXN = 100001;

int maxv[MAXN<<2], L, R, P, K;
long long sum[MAXN<<2];

void build(int i, int l, int r){
	if(l == r){
		scanf("%d", maxv + i);
		sum[i] = maxv[i];
		return;
	}
	int mid = (l + r) >> 1;
	build(left, l, mid);
	build(right, mid + 1, r);
	pull;
}

long long query(int i, int l, int r){
	if(l >= L && r <= R) return sum[i];
	int mid = (l + r) >> 1;
	return mid >= L ? (mid < R ? query(left, l, mid) + query(right, mid + 1, r) : query(left, l, mid)) : query(right, mid + 1, r);
}

void mod(int i, int l, int r){
	if(l == r){
		maxv[i] = (sum[i] %= K);
		return;
	}
	int mid = (l + r) >> 1;
	if(mid >= L && maxv[left] >= K) mod(left, l, mid);
	if(mid < R && maxv[right] >= K) mod(right, mid + 1, r);
	pull;
}

void rep(int i, int l, int r){
	if(l == r){
		maxv[i] = sum[i] = K;
		return;
	}
	int mid = (l + r) >> 1;
	if(mid >= P) rep(left, l, mid);
	else rep(right, mid + 1, r);
	pull;
}

int main(){
	int n, m, opt;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while(m-- && scanf("%d", &opt)) switch(opt){
		case 1:
			scanf("%d%d", &L, &R);
			printf("%I64d\n", query(1, 1, n));
			break;
			
		case 2:
			scanf("%d%d%d", &L, &R, &K);
			if(maxv[1] >= K) mod(1, 1, n);
			break;
			
		case 3:
			scanf("%d%d", &P, &K);
			rep(1, 1, n);
			break;
	}
	return 0;
}