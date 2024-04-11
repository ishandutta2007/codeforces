#include <bits/stdc++.h>
using namespace std;

#define N 1100005

int tot;
int prime[N];
bool vis[N];

void find_prime() {
	for (int i = 2; i < N ; i ++) {
		if (!vis[i]) prime[++ tot] = i;
		for (int j = 1 ; j <= tot && i * prime[j] < N; j ++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				break;
			}
        }
    }
    return;
}

int n;

int main() {
    find_prime();
    scanf("%d", &n);
    for (int i = 1; i <= 1000; i ++) {
        if (vis[i*n+1]) {
            printf("%d\n", i);
            return 0;
        }
    }
}