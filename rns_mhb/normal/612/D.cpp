#include <bits/stdc++.h>
using namespace std;

#define N 1000005

typedef pair <int, int> pii;

int n, k, a[N], b[N], c[N], d[N], cnt, acnt;
pii x[N<<1];

const int inf = 2e9;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d", &a[i], &b[i]);
		x[cnt++] = make_pair(a[i], -1);
		x[cnt++] = make_pair(b[i], +1);
	}
    sort(x, x + cnt);
    int sum = 0;
    int s, e = -inf;
    for(int i = 0; i < cnt; i++){
        if(sum <= -k){
        	int a = x[i - 1].first, b = x[i].first;
            if(a <= e) e = max(e, b);
            else{
            	if(e != -inf) c[acnt] = s, d[acnt++] = e;
                s = a, e = b;
            }
        }

        sum += x[i].second;
    }
    if(e != -inf){
    	c[acnt] = s, d[acnt++] = e;
    }
    printf("%d\n", acnt);
    for (int i = 0; i < acnt; i ++) {
		printf("%d %d\n", c[i], d[i]);
    }
	return 0;
}