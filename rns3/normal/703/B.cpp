#include <bits/stdc++.h>
using namespace std;

int c[100001], a[100001], vis[100001];

int main() {
	
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i ++) scanf("%d", &c[i]);
	for(int i = 0; i < k; i ++) scanf("%d", &a[i]), a[i] --;
	for(int i = 0; i < k; i ++) vis[a[i]] = 1;
	sort(a, a + k);
	long long tot = 0;
    long long A = 0, B = 0;
    for(int i = 0; i < n; i ++) if(vis[i]) A += c[i]; else B += c[i];
    tot = A * B;
    for(int i = 0; i < k; i ++) {
		A -= c[a[i]];
		tot += c[a[i]] * A;
    }
    for(int i = 0; i < n; i ++) if(!vis[i] && !vis[(i+1)%n]) tot += c[i] * c[(i+1)%n];
    printf("%I64d\n", tot);
}