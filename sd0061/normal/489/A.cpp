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
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , a[N];
pair<int , int> q[N];
void work () {
    cin >> n;
    int i , j , res = 0;
    for (i = 0 ; i < n ; ++ i)
        cin >> a[i];
    for (i = 0 ; i < n ; ++ i) {
        int x = i;
        for (j = i + 1 ; j < n ; ++ j)
            if (a[j] < a[x])
                x = j;
        if (x != i)
            q[++ res] = make_pair(i , x) , swap(a[x] , a[i]);
    }
    cout << res << endl;
    for (i = 1 ; i <= res ; ++ i)
        printf("%d %d\n" , q[i].first , q[i].second);
}

int main() {
    work();
    return 0;
}