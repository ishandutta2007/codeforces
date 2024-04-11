#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

#define N 300010

ll a[N], d[N], c[N], L, B, S;
int prv[N], nxt[N], cnt;
set <pii> s;

void fix() {
    while(!s.empty()) {
        pii P = *s.begin();
        if(P.first > S) break;
        int i = P.second;
        s.erase(s.begin());
        if(i == cnt) {
            cnt = prv[cnt];
            continue;
        }
        int l = prv[i], r = nxt[i];
        s.erase(pii(c[r], r));
        c[r] = (a[l] - a[r] + d[r] - d[l] - 1) / (d[r] - d[l]);
        s.insert(pii(c[r], r));
        nxt[l] = r, prv[r] = l;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    L = n, B = 0, S = 0;
    a[1] = 0, d[1] = 0;
    cnt = 1;
    while(m --) {
        int type, x, y;
        scanf("%d", &type);
        if(type == 1) {
            scanf("%d", &x);
            L += x;
            cnt = 1;
            a[1] = -B, d[1] = 0;
            s.clear();
        }
        if(type == 2) {
            scanf("%d", &x);
            nxt[cnt] = cnt+1;
            prv[cnt+1] = cnt;
            cnt ++;
            a[cnt] = -B-L*S, d[cnt] = L;
            c[cnt] = (a[cnt-1] - a[cnt] + d[cnt] - d[cnt-1] - 1) / (d[cnt] - d[cnt-1]);
            s.insert(pii(c[cnt], cnt));
            L += x;
        }
        if(type == 3) {
            scanf("%d%d", &x, &y);
            B += x, S += y;
        }
        fix();
        printf("%I64d %I64d\n", d[cnt]+1, B+a[cnt]+d[cnt]*S);
    }
}