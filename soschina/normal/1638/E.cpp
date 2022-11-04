#include <cstdio>
#define le (i << 1)
#define ri (i << 1 | 1)
using namespace std;
const int N = 1e6 + 1;

int n, q, col[N << 2];
long long val[N << 2], valc[N];
char s[6];

int L, R, P, C, K;
long long ans;

void push(int i){
	if(col[i]){
		val[le] += val[i];
		val[ri] += val[i];
		val[i] = 0;
		col[le] = col[i];
		col[ri] = col[i];
		col[i] = 0;
	}
}

void color(int i, int l, int r){
	int mid = (l + r) >> 1;
	if(l >= L && r <= R){
		if(col[i]) val[i] += valc[col[i]] - valc[C];
		else{
			color(le, l, mid);
			color(ri, mid + 1, r);
		}
		col[i] = C;
		return;
	}
	push(i);
	if(mid >= L) color(le, l, mid);
	if(mid < R) color(ri, mid + 1, r);
}

void query(int i, int l, int r){
	if(l == r){
		ans = val[i] + valc[col[i]];
		return;
	}
	push(i);
	int mid = (l + r) >> 1;
	if(mid >= P) query(le, l, mid);
	else query(ri, mid + 1, r);
}

int main(){
	scanf("%d%d", &n, &q);
	col[1] = 1;
	while(q--){
		scanf("%s", s);
		switch(s[0]){
			case 'C':{
				scanf("%d%d%d", &L, &R, &C);
				color(1, 1, n);
				break;
			}
			case 'A':{
				scanf("%d%d", &C, &K);
				valc[C] += K;
				break;
			}
			case 'Q':{
				scanf("%d", &P);
				query(1, 1, n);
				printf("%lld\n", ans);
				break;
			}
		}
	}
	return 0;
}