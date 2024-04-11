#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
using namespace std;
typedef long long LL;
const int N = 300005;
map< pair<LL , LL> , pair<LL , LL> > f;
pair<LL , LL> dfs(LL x , LL y) {
    if (x == 0)
        return make_pair(x || y , -y);
    if (x < 10)
        return make_pair(1LL , x - max(x , y));
    if (f.count({x , y}))
        return f[{x , y}];
    LL ans = 0 , p = 1;
    while (p * 10 <= x)
        p *= 10;
    pair<LL , LL> r = dfs(x % p , max(y , x / p));
    pair<LL , LL> b = dfs(x / p * p + r.second , y);
    ans = r.first + b.first;    
    return f[{x , y}] = make_pair(ans , b.second);
}

void work() {
    LL n;
    cin >> n;
    cout << dfs(n , 0).first << endl;
}

int main() {
    work();
    return 0;
}