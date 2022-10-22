#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10005;

LL n , m;
vector<LL> f;
int c = 100000;
void dfs(int k , int d) {
    if (!c) return;
    if (!k || !d) {
        -- c;
        cout << f[k] << ' ';
        return;
    }
    for (int i = 0 ; i <= k ; ++ i)
        if (f[k] % f[i] == 0)
            dfs(i , d - 1);
}

void work() {
    int i;
    cin >> n >> m;
    for (i = 1 ; (LL)i * i <= n ; ++ i)
        if (n % i == 0) {
            f.push_back(i);
            if ((LL)i * i != n)
                f.push_back(n / i);
        }
    sort(f.begin() , f.end());
    dfs(f.size() - 1 , m);
}

int main() {
    work();
    return 0;
}