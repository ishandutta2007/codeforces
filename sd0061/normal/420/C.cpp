#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <set>
#include <map>
typedef long long LL;
using namespace std;

#define N 300005
int n , p;
pair<int , int> a[N];
int deg[N];
vector<int> e[N];
LL ans;

int c[N];
void add(int x , int w) {
    for ( ; x > 0 ; x -= x & -x)
        c[x] += w;
}
int sum(int x) {
    int res = 0;
    for ( ; x <= n ; x += x & -x)
        res += c[x];
    return res;
}


void work()
{
    int i , j , x , y;
    scanf("%d%d",&n,&p);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d%d",&x,&y);
        ++ deg[x] , ++ deg[y];
        a[i] = make_pair(x , y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (i = 1 ; i <= n ; ++ i)
        add(deg[i] , 1);
    for (i = 1 ; i <= n ; ++ i) {
        if (deg[i] >= p) {
            ans += n - 1;
            continue;
        }
        for (j = 0 ; j < e[i].size() ; ++ j) {
            y = e[i][j];
            add(deg[y] , -1);
            -- deg[y];
            add(deg[y] , 1);
        }
        add(deg[i] , -1);
        ans += sum(p - deg[i]);
        add(deg[i] , 1);
        for (j = 0 ; j < e[i].size() ; ++ j) {
            y = e[i][j];
            add(deg[y] , -1);
            ++ deg[y];
            add(deg[y] , 1);
        }
    }
    cout << ans / 2 << endl;
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}