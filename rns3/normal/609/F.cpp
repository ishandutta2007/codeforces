#include <stdio.h>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
#define M 300001
typedef long long ll;

struct dat{
	int x,  z, id;
	ll y;
	dat(int x = 0, ll y = 0, int z = 0, int id = 0):x(x), y(y), z(z), id(id){}
}a[M];

struct mos{
	int x, y;
	mos(int x = 0, int y = 0):x(x), y(y){}
};

bool operator < (mos A, mos B) {
	if(A.x != B.x) return A.x < B.x;
	return A. y < B.y;
}

bool cmp(dat A, dat B) {
	if(A.x != B.x) return A.x < B.x;
	return 0;
}

multiset<mos> S;
multiset<mos>::iterator P[M];

ll v[M], mx[M], en[M], ans1[M], ans2[M];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%d %I64d", &a[i].x, &a[i].y), a[i].id = i;
	sort(a + 1, a + n + 1, cmp);
    int nn = sqrt(n), cnt = 0;
    for(int i = 1; i <= n; i ++) {
        if(i % nn == 0 || i == n) v[++cnt] = i;
    }
	for(int i = 1; i <= cnt; i ++) {
		for(int j = v[i-1] + 1; j <= v[i]; j ++) mx[i] = max(mx[i], a[j].x + a[j].y);
		en[i] = a[v[i]].x;
	}
    for(int step = 1; step <= m; step ++) {
    	int x, y;
    	scanf("%d %d", &x, &y);
    	//if(step % 1000 == 0) printf("%d\n", step / 1000);
    	int ok = 0, i;
		for(i = 1; i <= cnt; i ++) {
			if(en[i] > x) break;
            if(mx[i] >= x) {
                for(int j = v[i-1] + 1; j <= v[i]; j ++) if(a[j].x + a[j].y >= x) {
                    a[j].y += y;
                    a[j].z ++;
                    ok = j;
					goto END;
                }
                for(int j = v[i-1] + 1; j <= v[i]; j ++) mx[i] = max(mx[i], a[j].x + a[j].y);
            }
		}
		END:;
		if(!ok && i <= cnt) {
            for(int j = v[i-1] + 1; j <= v[i]; j ++) if(a[j].x <= x && a[j].x + a[j].y >= x) {
                a[j].y += y;
                a[j].z ++;
                ok = j;
                break;
            }
            for(int j = v[i-1] + 1; j <= v[i]; j ++) mx[i] = max(mx[i], a[j].x + a[j].y);
		}
		if(ok) {
            multiset<mos>::iterator it = S.lower_bound(mos(a[ok].x, -1));
            int cn = 0;
            for(; it != S.end(); it ++) {
                mos A = *it;
                if(A.x > a[ok].x + a[ok].y) break;
                a[ok].y += A.y;
                a[ok].z ++;
				P[cn ++] = it;
            }
            for(int i = 0; i < cn; i ++) S.erase(P[i]);
            for(int i = 1; i <= cnt; i ++) if(v[i] >= ok) {
				for(int j = v[i-1] + 1; j <= v[i]; j ++) mx[i] = max(mx[i], a[j].x + a[j].y);
				break;
            }
		}
		else S.insert(mos(x, y));
    }
    for(int i = 1; i <= n; i ++) {
    	ans1[a[i].id] = a[i].z;
		ans2[a[i].id] = a[i].y;
    }
    for(int i = 1; i <= n; i ++) printf("%I64d %I64d\n", ans1[i], ans2[i]);
}