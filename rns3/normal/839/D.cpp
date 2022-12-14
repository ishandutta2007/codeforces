#include <bits/stdc++.h>
using namespace std;

#define N 202020
#define K 1010101

typedef long long LL;
const int P = 1e9 + 7;

int a[K], n, p[N], b[K], go[N];

bool vis[K];

int cnt;
void prep() {
	for (int i = 2; i < K; i ++) if (!vis[i]) {
		p[++cnt] = i;
		for (LL j = 1ll * i * i; j < K; j += i) {
            vis[j] = 1;
		}
	}
	go[0] = 0;
	int now = 1;
	for (int i = 1; i < N; i ++) {
		go[i] = 1ll * i * now % P;
		now = 1ll * now * 2 % P;
	}
    //printf("%d\n", cnt);
}

int pp[N], aa[N];
vector<int> v;

void func(int k) {//printf("%d\n", k);
	int e = 0;
	int t = k;
	int to = 1;
	while (t > 1) {
		if (1ll * p[to] * p[to] > t) {
			aa[++e] = 1;
			pp[e] = t;
			break;
		}
        if (t % p[to] == 0) {
        	pp[++e] = p[to];
        	aa[e] = 0;
            while (t % p[to] == 0) {
				aa[e] ++;
				t /= p[to];
            }
        }
        to ++;
	}
	v.clear();
	v.push_back(1);
	for (int i = 1; i <= e; i ++) {
		for (int sz = v.size(), h = 0; h < sz; h ++) {
			int now = 1;
			for (int j = 1; j <= aa[i]; j ++) {
				now = now * pp[i];
				v.push_back(v[h] * now);
			}
		}
	}
	for (int i = 0; i < v.size(); i ++) {
		a[v[i]] ++;
	}
}


int main() {
	//freopen("r.in", "r", stdin);
	prep();//for (int i = 0; i < 10; i ++) printf("%d ", go[i]);puts("");
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i ++) {
		scanf("%d", &x);
		func(x);
	}//for (int i = 1; i < K; i ++) if (a[i]) printf("%d %d\n", i, a[i]);
    for (int i = 1; i < K; i ++) b[i] = go[a[i]];
    for (int i = K - 1; i >= 1; i --) {
        for (int j = i * 2; j < K; j += i) {
            b[i] = (P + b[i] - b[j]) % P;
        }
    }
    int ans = 0;
    for (int i = 2; i < K; i ++) ans = (ans + 1ll * i * b[i]) % P;
    printf("%d\n", ans);
	return 0;
}