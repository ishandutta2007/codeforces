#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 200005;

int n;
pair<int , int> a[N];
int dx[N] , dy[N] , Dx , Dy;
int cx[N] , cy[N];

inline LL S(int x) {
    return (LL)x * (x - 1) / 2;
}

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        a[i] = make_pair(x , y);
        dx[Dx ++] = x;
        dy[Dy ++] = y;
    }
    sort(dx , dx + Dx);
    Dx = unique(dx , dx + Dx) - dx;
    sort(dy , dy + Dy);
    Dy = unique(dy , dy + Dy) - dy;
    sort(a , a + n);
    for (int i = 0 ; i < n ; ++ i) {
        int x = lower_bound(dx , dx + Dx , a[i].first) - dx;
        int y = lower_bound(dy , dy + Dy , a[i].second) - dy;
        ++ cx[x];
        ++ cy[y];
    }
    LL res = 0;
    for (int i = 0 ; i < Dx ; ++ i)
        res += S(cx[i]);
    for (int i = 0 ; i < Dy ; ++ i)
        res += S(cy[i]);
    for (int i = 0 ; i < n ;) {
        int j = i;
        while (j < n && a[i] == a[j])
            ++ j;
        res -= S(j - i);
        i = j;
    }
    cout << res << endl;
    return 0;
}