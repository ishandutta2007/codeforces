#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int N = (int)2e5 + 500;

struct node{
    int a, l;
    bool rt;
    int cnt;
    node(int _a, int _l, bool _rt, int _cnt){a = _a, l = _l, rt = _rt, cnt = _cnt;}
};

int n,m;
int x[N], psum[N];
int new_loc[N];
P num[N];

node get_next(node prev){
    int i = prev.a, l = prev.l, cnt = prev.cnt;
    bool rt = prev.rt;
    int nxt_i, len;
    if(rt) nxt_i = int(upper_bound(psum, psum + n, psum[i-1] + l) - psum);
    else nxt_i = int(lower_bound(psum, psum + n, psum[i-1] - l) - psum) + 1;
    len = abs(psum[i-1] - psum[nxt_i - 1]);

    if(cnt > 0) return node(nxt_i, l - len, !rt, cnt-1);
    if(len == 0) return node(-1, -1, true, 0);

    if((l / len) % 2 == 0) nxt_i = i;
    bool nxt_rt = rt ^ ((l / len ) % 2 == 1);
    int nxt_l = l % len;
    return node(nxt_i, nxt_l, nxt_rt, cnt);
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &num[i].first);
        num[i].second = i;
    }
    sort(num + 1, num + n + 1);
    for(int i = 1; i <= n; i++){
        x[i] = num[i].first;
        new_loc[num[i].second] = i;
    }
    for(int i = 0; i < n; i++) psum[i] = x[i+1];

    while(m--){
        int a, l;
        scanf("%d%d", &a, &l);
        a = new_loc[a];
        bool rt = true;
        node cur = {a, l, rt, 1};
        while(true){
            node nxt = get_next(cur);
            if(nxt.a == -1) break;
            cur = nxt;
        }
        printf("%d\n", num[cur.a].second);
    }
}