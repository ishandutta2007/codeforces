#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f3(i, a, b) for (int i = a; i >= b; i --)

typedef vector <int> vi;

#define N 5010

int n, K, V, cnt[N], a[N], c[N], d[N], tot;
bool dp[N][N], ep[N][N];
vi v, w;

int func(vi &v) {
    int res = 0;
    if (v.empty()) return res;
    res = v.back();
	int sz = v.size(), b;
	f0(i, 0, sz - 1) {
		b = v[i];
		cnt[tot] = (a[b] + K - 1) / K;
		c[tot] = b; d[tot] = res;
		a[res] += a[b]; a[b] = 0; tot ++;
	}
	return res;
}

int main() {
    scanf("%d %d %d", &n, &K, &V);
    int sum = 0;
    f1(i, 1, n) scanf("%d", &a[i]), sum += a[i];
    if (sum < V) puts("NO");
    else {
        dp[0][0] = 1;
        f1(i, 1, n) {
            f0(j, 0, K) if (dp[i-1][j]) {
                dp[i][j] = 1; ep[i][j] = 1;
                dp[i][(j+a[i])%K] = 1;
            }
        }
        int b = V % K;
        if (!dp[n][b]) puts("NO");
        else {
            puts("YES");
			f3(i, n, 1) {
                if (ep[i][b]) {w.pb(i); continue;}
                else {
                    b = b - a[i] % K + K;
                    if (b >= K) b -= K;
                    v.pb(i);
                }
			}
            int x = func(v);
            int y = func(w);
            if (!x) {
                int z;
                f1(i, 1, n) if (!a[i]) {z = i; break;}
                cnt[tot] = V / K;
                c[tot] = y; d[tot] = z; tot ++;
            }
            else {
                if (y) {
                    cnt[tot] = a[y] / K;
                    c[tot] = y; d[tot] = x;
                    a[x] += a[y] / K * K; a[y] = 0;
					tot ++;
                }
                int z;
                f1(i, 1, n) if (!a[i]) {z = i; break;}
                cnt[tot] = (a[x] - V) / K;
                c[tot] = x, d[tot] = z; tot ++;
            }
            f0(i, 0, tot) if (cnt[i]) printf("%d %d %d\n", cnt[i], c[i], d[i]);
        }
    }
	return 0;
}