#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 100005
int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
int val[N] , s[N] , f[N];
pair<int , int> a[N];
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}
void work() {
    int i , j , x , y , z;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d", &val[i]);
        a[i] = make_pair(val[i] , i);
        f[i] = i , s[i] = 1;
    }
    sort(a + 1 , a + 1 + n , greater< pair<int , int> >());
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    LL ans = 0;
    for (j = 1 ; j <= n ; ++ j) {
        x = a[j].second;
        vector<int> con;

        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x , z = val[y];
            if (make_pair(z , y) <= a[j])
                continue;
            if (getf(y) != getf(x))
                con.push_back(getf(y));
        }
        sort(con.begin() , con.end());
        con.erase(unique(con.begin() , con.end()) , con.end());
        int sum = 0;
        for (i = 0 ; i < con.size() ; ++ i) {
            ans += (LL) val[x] * s[con[i]] * sum;
            sum += s[con[i]];
        }
        ans += (LL) val[x] * sum;
        for (i = 0 ; i < con.size() ; ++ i) {
            f[con[i]] = x , s[x] += s[con[i]];
        }
    }
    printf("%.10f\n" , 2.0 * ans / n / (n - 1));

}

int main()
{
    work();
    return 0;
}