#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 200019
#define ll long long int 
using namespace std;

int n, p;
int a[maxn];
pii b[maxn];
set<int> s;
ll ans[maxn];
queue<int> tank;
set<int> stank;
int main(){
    scanf("%d%d", &n, &p);
    rep(i, 1, n) scanf("%d", &a[i]), b[i] = pii(a[i], i);
    sort(b + 1, b + 1 + n);
    ll nowt = 0, nowp = 1;
    while (nowp <= n){
        if (s.empty()){
            s.insert(b[nowp++].se), nowt = b[nowp - 1].fi;
            while (nowp <= n && nowt >= b[nowp].fi) s.insert(b[nowp++].se); 
        }
        while (!s.empty()){
            if (tank.empty()) {
                int op = *s.begin(); s.erase(s.begin());
                tank.push(op), stank.insert(op);
            }
            while (!tank.empty()){
                int op = tank.front(); tank.pop();
                nowt += p, ans[op] = nowt;
                while (nowp <= n && nowt >= b[nowp].fi) {
                    s.insert(b[nowp++].se); 
                    if (*s.begin() < *stank.begin()){
                        int tt = *s.begin(); s.erase(s.begin());
                        tank.push(tt), stank.insert(tt);
                    }
                }
                stank.erase(op);
                if (!s.empty() && *s.begin() < *stank.begin()){
                    int tt = *s.begin(); s.erase(s.begin());
                    tank.push(tt), stank.insert(tt);
                }
            }
        }
    }
    rep(i, 1, n) printf("%lld ", ans[i]);
    return 0;
}