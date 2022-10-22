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

#define N 100005
int n , m , cnt;
bool f[N];
set<int> h;
pair<int , int> a[N];
void work()
{
    int i , x , y;
    char s[5];
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < m ; ++ i) {
        scanf("%s%d" , s , &x);
        if (*s == '+') {
            a[i] = make_pair(1 , x);
        } else {
            a[i] = make_pair(0 , x);
        }
    }
    for (i = m - 1 ; i >= 0 ; -- i) {
        x = a[i].second;
        if (a[i].first) {
            h.erase(x);
        } else {
            h.insert(x);
        }
    }
    for (i = 0 ; i < m ; ++ i) {
        x = a[i].second;
        if (a[i].first) {
            if (h.size())
                f[x] = 1;
            else if (i != 0) {
                if (i && a[i - 1].second == x && a[i - 1].first != 1)
                    continue;
                f[x] = 1;
            }
            h.insert(x);
        } else {
            h.erase(x);
            if (h.size())
                f[x] = 1;
            else if (i != m - 1) {
                if (a[i + 1].second == x && a[i + 1].first != 0)
                    continue;
                f[x] = 1;
            }
        }
    }
    x = 0;
    for (i = 1 ; i <= n ; ++ i)
        x += !f[i];
    printf("%d\n" , x);
    for (i = 1 ; i <= n ; ++ i) {
        if (!f[i])
            printf("%d " , i);
    }
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}