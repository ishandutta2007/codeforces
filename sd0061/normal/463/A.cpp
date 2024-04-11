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
int n , s;

void work() {
    int ans = -1 , x , y , i;
    scanf("%d%d",&n,&s);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        if (y)
            ++ x;
        else
            y = 100;
        if (s >= x)
            ans = max(ans , 100 - y);
    }
    cout << ans << endl;
}

int main() {
    work();
    return 0;
}