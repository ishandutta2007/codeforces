#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/MTACK:16777216")
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m , K , pre[N] , mcnt;
struct edge {
    int x , w , next;
}e[8 * N];
pair<int , int> p[N];
priority_queue< pair<LL , int> > Q;
LL d[N];
bool f[N];
int c[N];

void Dijkstra() {
    int i , x , y , z;
    for (i = 1 ; i <= n ; ++ i)
        d[i] = 1LL << 60 , f[i] = 0;
    d[1] = 0 , c[1] = 1 , Q.push(make_pair(0LL , 1));
    while (!Q.empty()) {
        x = Q.top().second, Q.pop();
        if (f[x]) continue; f[x] = 1;
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x , z = e[i].w;
            if (d[x] + z < d[y]) {
                d[y] = d[x] + z;
                c[y] = c[x];
                Q.push(make_pair(-d[x] - z , y));
            } else if (d[x] + z == d[y]) {
                c[y] += c[x];
                if (c[y] > 2)
                    c[y] = 2;
            }
        }
    }
}

void work() {
    int i , x ,y , z;
    scanf("%d%d%d",&n,&m,&K);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
    }
    for (i = 0 ; i < K ; ++ i) {
        scanf("%d%d",&y,&z) , x = 1;
        p[i] = make_pair(y , z);
    }
    int res = 0;
    sort(p , p + K);
    res = unique(p , p + K) - p;
    i = res , res = K - i , K = i;
    for (i = 0 ; i < K ; ++ i) {
        y = p[i].first , z = p[i].second , x = 1;
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
    }
    Dijkstra();

    for (i = 0 ; i < K ; ++ i) {
        y = p[i].first , z = p[i].second , x = 1;
        if (d[y] < z)
            ++ res;
        else if (d[y] == z && c[y] > 1)
            ++ res;
    }
    cout << res << endl;
}

int main()
{
    work();
    return 0;
}