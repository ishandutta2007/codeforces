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
int n;

void work() {
    int ans = -1 , x , y , i;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&x);
        ans = max(ans , x);
    }
    cout << ans << endl;
}

int main() {
    work();
    return 0;
}