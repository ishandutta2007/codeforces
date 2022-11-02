#include <bits/stdc++.h>
using namespace std;
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f3(i, a, b) for (int i = a; i >= b; i --)
void chkmax(int &a, int b) {if (a < b) a = b;}
void chkmin(int &a, int b) {if (a > b) a = b;}
#define N 100005
const int inf = 0x3f3f3f3f;

int a[N], s[N], t[N], sum[N], as, mx[N];
int n, d;

int main() {
    scanf("%d %d", &n, &d);
    f1(i, 1, n) scanf("%d", &a[i]);
    int now = 0, ans = 0;
    f1(i, 1, n) t[i] = inf;
	f1(i, 1, n) {
        if (a[i] == 0) {
            s[i] = 0; as ++;
            chkmax(now, 0);
        }
        else {
            s[i] = s[i-1] + a[i];
			chkmin(t[as], d - s[i]);
            sum[as] = s[i];
            now += a[i];
            if (now > d) {
                puts("-1");
                return 0;
            }
        }
	}
    t[as+1] = d;
	f3(i, as, 1) chkmin(t[i], t[i+1] - sum[i]), chkmin(t[i], d);
    as = 0; now = 0;
    f1(i, 1, n) {
        if (a[i] == 0) {
			++ as;
            if (now < 0) ans ++, now = t[as];
        }
        else now += a[i];
    }
    printf("%d\n", ans);
}