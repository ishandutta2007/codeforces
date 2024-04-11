#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 1;

int t, n, k, a[N];

struct node{
    int l, pos;
    node(int l, int pos) : l(l), pos(pos){}
    bool operator<(const node &b) const{
        return a[pos] / l < a[b.pos] / b.l;
    }
};
priority_queue<node> pq;

int main(){
    scanf("%d", &t);
    while(t--){
        while(pq.size())
            pq.pop();
        scanf("%d%d", &n, &k);
        int mina = 1e5;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            mina = min(mina, a[i]);
            pq.push(node(1, i));
        }
        int ans = 1e5;
        while(pq.top().l <= k){
            node nd = pq.top();
            pq.pop();
            ans = min(ans, a[nd.pos] / nd.l - mina);
            if(a[nd.pos] / nd.l == 0){
                mina = 0;
                pq.push(node(k + 1, nd.pos));
                continue;
            }
            int r = a[nd.pos] / (a[nd.pos] / nd.l) + 1;
            if(r > k)
                break;
            mina = min(mina, a[nd.pos] / r);
            pq.push(node(r, nd.pos));
        }
        printf("%d\n", ans);
    }
    return 0;
}