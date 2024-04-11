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
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , a[N] , m;
int s0[N] , s1[N];
vector< pair<int , int> > res;
void work() {
    int i , x , y , t;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d", &a[i]) , -- a[i];
        s0[i] = s0[i - 1] + !a[i];
        s1[i] = s1[i - 1] + a[i];
    }
    for (t = 1 ; t <= n ; ++ t) {
        x = y = 0;
        int w = 0 , l = 0 , f = -1;
        i = 0;
        while (i < n) {
            x = lower_bound(s0 , s0 + n + 1 , s0[i] + t) - s0;
            y = lower_bound(s1 , s1 + n + 1 , s1[i] + t) - s1;
            if (s0[x] != s0[i] + t && s1[y] != s1[i] + t)
                break;
            if (x < y) {
                ++ w , f = 1;
            } else {
                ++ l , f = 0;
            }
            i = min(x , y);
        }
        if (i < n)
            continue;
//        for (i = 0 ; i < n ; ++ i) {
//            if (a[i])
//                ++ x;
//            else
//                ++ y;
//            if (x >= t) {
//                ++ w;
//                f = 1;
//                x = y = 0;
//            } else if (y >= t) {
//                ++ l;
//                f = 0;
//                x = y = 0;
//            }
//        }
        if (w == l)
            continue;
        if (w > l && !f) continue;
        if (w < l && f) continue;
        res.push_back(make_pair(max(w , l) , t));
    }
    sort(res.begin() , res.end());
    printf("%d\n" , res.size());
    for (i = 0 ; i < res.size() ; ++ i)
        printf("%d %d\n" , res[i].first , res[i].second);
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}