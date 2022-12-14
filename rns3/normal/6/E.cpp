#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 100011
#define LOG 20
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int pow[LOG];
int n, k;
int a[N];
int mx[N][LOG], mn[N][LOG];
int first[N];

int log2(int a){
	for(int i=LOG-1; i>=0; i--) if(pow[i] <= a) return i;
}

int rmq(int i, int len, int log){
	if(pow[log] == len) return mx[i][log] - mn[i][log];
	return max(mx[i][log], mx[i+len-pow[log]][log]) - min(mn[i][log], mn[i+len-pow[log]][log]);
}

int ok(int mid){
	int ans = 0, log = log2(mid);
	for(int i=1; i<=n-mid+1; i++){
		if(rmq(i, mid, log) <= k) first[ans++] = i;
	}
	return ans;
}

int main(){
	pow[0] = 1;
	for(int i=1; i<LOG; i++) pow[i] = pow[i-1] * 2;

	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);

	for(int i=1; i<=n; i++) mx[i][0] = mn[i][0] = a[i];

	for(int i=1; i<LOG; i++){
		int len = (1 << i);
		for(int j=1; j<=n-len+1; j++){
			mx[j][i] = max(mx[j][i-1], mx[j+len/2][i-1]);
			mn[j][i] = min(mn[j][i-1], mn[j+len/2][i-1]);
		}
	}

	int st = 1, en = n + 1, cnt = 0;

	while(st + 1 < en){
		int mid = (st + en) / 2;
		cnt = ok(mid);
		if(cnt) st = mid;
		else en = mid;
	}

	cnt = ok(st);

	printf("%d %d\n", st, cnt);
	for(int i=0; i<cnt; i++) printf("%d %d\n", first[i], first[i] + st - 1);
}