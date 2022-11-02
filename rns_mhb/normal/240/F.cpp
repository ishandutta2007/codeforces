#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;

struct data {
    int cnt[N<<2], setted[N<<2];
    char c;
    void push_up(int id) {
        cnt[id] = cnt[id<<1] + cnt[id<<1|1];
    }
    void build(int l, int r, int id, char *s) {
        setted[id] = -1;
        if (l == r) {
            cnt[id] = (s[l] == c?1:0);
            return;
        }
        int m = l + r >> 1;
        build(l, m, id<<1, s);
        build(m + 1, r, id<<1|1, s);
        push_up(id);
    }
    void reset_delta(int id, int l, int val) {
        cnt[id] = l * val;
        setted[id] = val;
    }
    void update(int L, int R, int val, int l, int r, int id) {
        if (L <= l && r <= R) {
            reset_delta(id, r - l + 1, val);
            return;
        }
        int m = l + r >> 1;
        if (setted[id] >= 0) {
            reset_delta(id<<1, m - l + 1, setted[id]);
            reset_delta(id<<1|1, r - m, setted[id]);
            setted[id] = -1;
        }
        if (m >= L) update(L, R, val, l, m, id<<1);
        if (m < R) update(L, R, val, m + 1, r, id<<1|1);
        push_up(id);
    }
    int query(int L, int R, int l, int r, int id) {
        if (L <= l && r <= R) return cnt[id];
        int m = l + r >> 1;
        if (setted[id] >= 0) {
            reset_delta(id<<1, m - l + 1, setted[id]);
            reset_delta(id<<1|1, r - m, setted[id]);
            setted[id] = -1;
        }
        int ans = 0;
        if (m >= L) ans += query(L, R, l, m, id<<1);
        if (m < R) ans += query(L, R, m + 1, r, id<<1|1);
        return ans;
    }
}T[26];




int n, m;
char s[N];
int a[30];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    scanf("%d%d%s", &n, &m, s + 1);
    for (int i = 0; i < 26; i ++) {
        T[i].c = 'a' + i;
        T[i].build(1, n, 1, s);
    }
    int l, r;
    while (m --) {
        scanf("%d%d", &l, &r);
        int flag = (r - l + 1) % 2;
        for (int i = 0; i < 26; i ++) {
            a[i] = T[i].query(l, r, 1, n, 1);
            if (a[i]&1) flag --;
            if (flag < 0) break;
        }
        if (flag < 0) continue;
        int x = l, y = r;
        for (int i = 0; i < 26; i ++) {
            T[i].update(l, r, 0, 1, n, 1);
			if (a[i] >= 2) {
				T[i].update(x, x + (a[i]>>1)-1, 1, 1, n, 1);
				T[i].update(y - (a[i]>>1) + 1, y, 1, 1, n, 1);
			}
			x += (a[i]>>1), y -= (a[i]>>1);
			if (a[i]&1) {
				int m = (l + r) >> 1;
				T[i].update(m, m, 1, 1, n, 1);
			}
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 26; j ++) {
            if (T[j].query(i, i, 1, n, 1)) {
                putchar('a' + j);
                break;
            }
        }
    }
    return 0;
}