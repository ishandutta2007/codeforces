#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;
const int M = 2000005;
int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];

bool f[M];
vector<int> fac[M];

int NumQ;
vector<int> Q[N];
stack< pair<int , int> > S[N << 1];
int ans[N] , a[N] , tot;

void init() {
    int i , j;
    for (i = 2 ; i * i < M ; ++ i) if (!f[i]) {
        for (j = i * i ; j < M ; j += i) {
            f[j] = 1;
        }
    }
    for (i = 2 ; i < M ; ++ i)
        if (!f[i]) {
            for (j = i ; j < M ; j += i)
                fac[j].push_back(tot);
            tot ++;
        }
    //cout << tot << endl;
}

void dfs(int x , int fa , int dep) {
    int i , j , y;

    if (Q[x].size()) {
        y = a[x];
        pair<int , int> res(-1 , -1);
        for (i = 0 ; i < fac[y].size() ; ++ i) {
            j = fac[y][i];
            if (S[j].size())
                res = max(res , S[j].top());
        }
        while (!Q[x].empty()) {
            ans[Q[x].back()] = res.second;
            Q[x].pop_back();
        }
    }
    y = a[x];
    for (i = 0 ; i < fac[y].size() ; ++ i) {
        j = fac[y][i];
        S[j].push(make_pair(dep , x));
    }
    for (i = pre[x] ; ~i ; i = e[i].next) {
        y = e[i].x;
        if (y != fa)
            dfs(y , x , dep + 1);
    }
    y = a[x];
    for (i = 0 ; i < fac[y].size() ; ++ i) {
        j = fac[y][i];
        S[j].pop();
    }
}

void work() {
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }

    for (i = 0 ; i <= m ; ++ i) {
        if (i < m)
            scanf("%d",&j);
        if (i == m || j == 2) {
            dfs(1 , 0 , 0);
            for (j = 0 ; j < NumQ ; ++ j)
                printf("%d\n" , ans[j]);
            NumQ = 0;
            scanf("%d%d",&x,&y);
            a[x] = y;
        } else {
            scanf("%d",&x);
            Q[x].push_back(NumQ ++);
        }
    }

}

int main() {
    init();
    work();
    return 0;
}