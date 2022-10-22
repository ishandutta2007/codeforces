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
#include <cassert>
using namespace std;
typedef long long LL;

#define N 1000

int n , m;
pair<int ,  pair<int , int> > a[N];
pair<int , int> b[N];
bool f[N];
int re[N] , ans , cnt;

bool find(int x) {
    for (int y = 0 ; y < m ; ++ y) {
        if (a[x].second.first <= b[y].first && !f[y]) {
            f[y] = 1;
            if (!~re[y] || find(re[y])) {
                re[y] = x;
                return 1;
            }
        }
    }
    return 0;
}

void work() {
    int i , j;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&a[i].second.first , &a[i].first) , a[i].second.second = i + 1;
    }
    sort(a , a + n , greater< pair<int ,  pair<int , int> > >() );
    scanf("%d",&m);
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d",&b[i].first) , b[i].second = i + 1;
    }
    sort(b , b + m);
    memset(re , -1 , sizeof(re));
    for (i = 0 ; i < n ; ++ i) {
        memset(f , 0 , sizeof(f));
        if (find(i)) {
            ++ cnt;
            ans += a[i].first;
        }
    }
    printf("%d %d\n" , cnt , ans);
    for (i = 0 ; i < m ; ++ i) {
        if (~re[i]) {
            printf("%d %d\n" , a[re[i]].second.second , b[i].second);
        }
    }
}

int main(){
    //freopen("1.txt" , "r" , stdin);
        work();
    return 0;
}