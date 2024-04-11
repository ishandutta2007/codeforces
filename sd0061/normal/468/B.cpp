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
const int N = 200005;

int n , a , b , A[N];
map<int , int> hash;
int pre[N + N] , mcnt;
struct edge {
    int x , next;
}e[N << 2];

int ncnt , scnt , bel[N] , low[N] , dfn[N];
int f[N];
stack<int> S;
void dfs(int x) {
    int i , y;
    low[x] = dfn[x] = ++ ncnt;
    f[x] = 1 , S.push(x);
    for (i = pre[x] ; ~i ; i = e[i].next) {
        y = e[i].x;
        if (!dfn[y]) {
            dfs(y);
            low[x] = min(low[x] , low[y]);
        } else if (f[y])
            low[x] = min(low[x] , dfn[y]);
    }
    if (low[x] == dfn[x]) {
        do {
            i = S.top() , S.pop() , f[i] = 0;
            bel[i] = scnt;
        }while (i != x);
        ++ scnt;
    }
}

void work() {
    int i , j;
    scanf("%d%d%d",&n,&a,&b);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&A[i]);
        hash[A[i]] = i;
    }
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i <= n ; ++ i) {
        if (hash.count(a - A[i])) {
            j = hash[a - A[i]];
            e[mcnt] = (edge) {j , pre[i]} , pre[i] = mcnt ++;
            e[mcnt] = (edge) {i + n , pre[j + n]} , pre[j + n] = mcnt ++;
        } else
            e[mcnt] = (edge) {i + n , pre[i]} , pre[i] = mcnt ++;

        if (hash.count(b - A[i])) {
            j = hash[b - A[i]];
            e[mcnt] = (edge) {j + n , pre[i + n]} , pre[i + n] = mcnt ++;
            e[mcnt] = (edge) {i , pre[j]} , pre[j] = mcnt ++;
        } else
            e[mcnt] = (edge) {i , pre[i + n]} , pre[i + n] = mcnt ++;
    }
    for (i = 1 ; i <= n + n ; ++ i)
        if (!dfn[i])
            dfs(i);
    for (i = 1 ; i <= n ; ++ i)
        if (bel[i] == bel[i + n])
            break;
    if (i <= n) {
        puts("NO");
        return;
    }
    puts("YES");
    for (i = 1 ; i <= n ; ++ i) {
        printf("%d " , bel[i] > bel[i + n]);
    }

}

int main() {
    work();
    return 0;
}