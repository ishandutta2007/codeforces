#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , m ;
int a[N] , d[N] , D;
int deg[N] , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];

void addedge(int x , int y) {
    e[mcnt] = (edge) {y , pre[x]};
    pre[x] = mcnt ++ , ++ deg[y];
}

void work() {
    int i , j , k , x , y;
    scanf("%d%d",&n,&m);
    int num = m;
    memset(pre , -1 , sizeof(pre));
    for (i = 0 ; i < n ; ++ i) {
        D = 0;
        for (j = 0 ; j < m ; ++ j) {
            scanf("%d",&a[j]);
            if (~a[j])
                d[D ++] = a[j];
        }
        sort(d , d + D) , D = unique(d , d + D) - d;
        for (j = 0 ; j < m ; ++ j) {
            if (!~a[j])
                continue;
            k = lower_bound(d , d + D , a[j]) - d;
            addedge(num + k , j);
            if (k + 1 != D)
                addedge(j , num + k + 1);
        }
        num += D;
    }
    queue<int> Q;
    vector<int> res;
    for (i = 0 ; i < num ; ++ i)
        if (!deg[i])
            Q.push(i);
    while (!Q.empty()) {
        x = Q.front() , Q.pop();
        res.push_back(x + 1);
        for (i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (!-- deg[y])
                Q.push(y);
        }
    }
    if (res.size() != num) 
        puts("-1");
    else {
        for (auto it : res)
            if (it <= m)
                printf("%d " , it);
    }
}

int main() {
    work();
    return 0;
}