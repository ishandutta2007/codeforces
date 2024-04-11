#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long LL;

#define N 100005
int n , a[N] , p[N];
bool f[N];
int G[N] , pre[N];
vector< pair<int , int> > res;
void work() {
    int i , j;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , p[a[i]] = i;
    for (i = 2 ; i * i <= n ; ++ i) if (!f[i])
        for (j = i * i ; j <= n ; j += i) f[j] = 1;
    for (i = 2 ; i <= n ; ++ i) {
        if (!f[i])
            pre[i] = i;
        else
            pre[i] = pre[i - 1];
    }
    for (i = n ; i >= 1 ; -- i) {
        while (a[i] != i) {
            int x = i - p[i] + 1;
            int y = pre[x];
            int z = p[i] + y - 1;
            res.push_back(make_pair(p[i] , z));
            j = p[i];
            swap(a[j] , a[z]);
            p[a[j]] = j;
            p[a[z]] = z;
        }
    }
    printf("%d\n" , res.size());
    for (i = 0 ; i < res.size() ; ++ i) {
        printf("%d %d\n" , res[i].first , res[i].second);
    }
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}