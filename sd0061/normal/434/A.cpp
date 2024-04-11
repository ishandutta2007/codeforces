#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
#define N 100005
int n , m , a[N];
vector<int> p[N];
long long sum , ans;
void work() {
    int i , j , k ;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= m ; ++ i)
        scanf("%d",&a[i]);
    m = unique(a + 1 , a + 1 + m) - a - 1;
    for (i = 1 ; i <= m ; ++ i)
        p[a[i]].push_back(i);
    for (i = 2 ; i <= m ; ++ i)
        sum += abs(a[i] - a[i - 1]);
    ans = sum;
    for (i = 1 ; i <= n ; ++ i) {
        vector<int> b; LL x = 0 , y = 0;
        for (j = 0 ; j < p[i].size() ; ++ j) {
            if (p[i][j] > 1)
                b.push_back(a[p[i][j] - 1]) , x += abs(a[p[i][j] - 1] - i);
            if (p[i][j] < m)
                b.push_back(a[p[i][j] + 1]) , x += abs(a[p[i][j] + 1] - i);
        }
        if (!b.size()) continue;
        nth_element(b.begin() , b.begin() + b.size() / 2 , b.end()) , k = b[b.size() / 2];
        for (j = 0 ; j < b.size() ; ++ j)
            y += abs(b[j] - k);
        ans = min(ans , sum - x + y);
    }
    cout << ans << endl;
}

int main()
{
    work();
    return 0;
}