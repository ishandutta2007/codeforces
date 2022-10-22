#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , X , Y;
vector<int> e[N];
int cnt;

int dfs(int x , int fa) {
    int s = 0;
    for (auto &y : e[x]) {
        if (y != fa) {
            int w = dfs(y , x);
            s += w;
        }
    }
    //cout << x << ' ' << s << endl;
    if (s >= 2) {
        -- cnt;
        //cnt += s - 2;
        return 0;
    } else {
        if (s == 0)
            ++ cnt;
        return 1;
    }
}

int main() {
    scanf("%d%d%d" , &n , &X , &Y);
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if (X > Y) {
        LL res = (LL)(n - 1) * Y;
        for (int i = 1 ; i <= n ; ++ i) {
            if (e[i].size() + 1 == n) {
                res += X - Y;
                break;
            }
        }
        cout << res << endl;
    } else {
        dfs(1 , 0);
        //cout << cnt << endl;
        -- cnt;
        cnt = n - cnt - 1;
        //cout << cnt << endl;
        cout << (LL)cnt * X + (LL)(n - 1 - cnt) * Y << endl;
    }
    return 0;
}