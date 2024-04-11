#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = (int)1e6 + 5;

ll m;
ll h[2],a[2],x[2],y[2],p[2],q[2];

ll get_next(ll &cur, int id){
    for(int i = 0; i < M; i++){
        if(cur == a[id]){
            return i;
        }
        cur = (cur * x[id] + y[id]) % m;
    }
    return -1;
}

ll get(int id){
    ll cur = h[id];
    p[id] = q[id] = -1;

    if((q[id] = get_next(cur, id)) == -1) return -1;

    cur = (cur * x[id] + y[id]) % m;

    p[id] = get_next(cur, id);
    if(p[id] != -1) p[id] ++;

    return 1;
}

int main(){
    cin >> m;
    for(int i = 0; i < 2; i++) cin >> h[i] >> a[i] >> x[i] >> y[i];
    for(int i = 0; i < 2; i++){
        if(get(i) == -1) return !printf("-1");
    }
    if(p[0] == -1 && p[1] == -1) return !printf("%I64d\n",q[0] == q[1] ? q[0] : -1);
    if(p[0] == -1 || p[1] == -1){
        int id = (p[0] != -1 ? 1 : 0);
        return !printf("%I64d\n", q[id] % p[!id] == q[!id] % p[!id] && q[id] >= q[!id] ? q[id] : -1);
    }
    ll cur = q[0];
    for(int i = 0; i < M; i++){
        if(cur % p[1] == q[1] % p[1] && cur >= q[1]) return !printf("%I64d\n", cur);
        cur += p[0];
    }
    return !printf("-1");
}