#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
typedef long long LL;
int n , m , s , pre[N] , mcnt;
struct edge {
    int x , w , next;
}e[N << 1];
LL d[N];
bool f[N];
pair<int , int> res[N];

int main() {
    int i , x , y , z;
    scanf("%d%d" , &n , &m);
    memset(pre , -1 , sizeof(pre));
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d%d" , &x , &y , &z);
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;        
    }
    priority_queue< pair<LL , int> > Q;
    for (i = 1 ; i <= n ; ++ i) {
        d[i] = 1LL << 60;
        res[i] = make_pair(1 << 30 , -1);
    }
    scanf("%d" , &s);
    d[s] = 0;
    Q.push(make_pair(d[s] , s));
    while (!Q.empty()) {
        x = Q.top().second , Q.pop();
        if (f[x]) continue; f[x] = 1;
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x;
            if (!f[y] && d[y] > d[x] + e[i].w) {
                d[y] = d[x] + e[i].w;
                Q.push(make_pair(-d[y] , y));
            }
        }
    }
    for (i = 0 ; i < mcnt ; i += 2) {
        x = e[i].x , y = e[i ^ 1].x , z = e[i].w;
        if (d[x] + z == d[y]) 
            res[y] = min(res[y] , make_pair(z , i >> 1));
        if (d[y] + z == d[x]) 
            res[x] = min(res[x] , make_pair(z , i >> 1));        
    }
    LL sum = 0;
    for (i = 1 ; i <= n ; ++ i)
        if (i != s)
            sum += res[i].first;
    printf("%lld\n" , sum);
    for (i = 1 ; i <= n ; ++ i)
        if (i != s)
            printf("%d " , res[i].second + 1);
    return 0;
}